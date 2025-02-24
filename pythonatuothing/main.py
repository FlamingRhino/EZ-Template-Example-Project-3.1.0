# Example file showing a circle moving on screen
from pickle import FALSE, TRUE
from turtle import distance
import pygame
from help_menu import draw_menu  # Import draw_menu function from help_menu.py
from write_to_file import write_to_filef  # Import write_to_file function from write_to_file.py
from read_form_line import read_functions_from_file, display_function_menu

# pygame setup ww 
pygame.init()
screen = pygame.display.set_mode((1280, 720))
clock = pygame.time.Clock()
running = True
dt = 0

# Center the player position
player_pos = pygame.Vector2(0, 0)
camera_offset = pygame.Vector2(0, 0)
player_angle = 0  # Variable to store the player's angle
zoom_factor = 1.0  # Variable to store the zoom factor
line_start_pos = None  # Variable to store the start position of the line
intake_state = 0  # Variable to store the intake state
arm_pos = 10  # Variable to store the arm position
angle_offset = 0  # Variable to store the angle offset

# Load the image for the field object
field_object_image = pygame.image.load("pythonatuothing\\images\\TopViewhighstakesfield.png").convert_alpha()

# Load the image for the player
player_image = pygame.image.load("pythonatuothing\\images\\ROBOTphoto.png").convert_alpha()

# Scale the player image to a fraction of the field object size
player_scale_factor = 0.1  # Adjust this value to change the relative size of the player dont scale player image
#player_image = pygame.transform.scale(player_image, (int(field_object_image.get_width() * player_scale_factor), int(field_object_image.get_height() * player_scale_factor)))

# Center the field object position
field_object_pos = pygame.Vector2(-550, -375)

# List to store line points
line_points = []

# Initialize font
font = pygame.font.Font(None, 36)

line_start_pos = player_pos.copy()

# Initialize a variable to store the player's position when L is first pressed
initial_player_pos = None

# Combined list to store all distances and angles
combined_list = []

# Dictionary to store saved positions and angles
saved_positions = {}

# Variable to store the current mode ("place" or "set")
mode = "place"

# Variable to track line drawing mode
line_drawing_mode = False

# Variable to track scroll offset
scroll_offset = 0

# Variable to track if the menu is open
menu_open = False

# Variable to track if the text box is open
text_box_open = False

# Variable to track if the code should be printed to a file
print_to_file = False

# Variable to store the input angle
input_angle = ""

# Variable to store the input function
input_function = ""

# Load functions from src/autons_maker.cpp
functions = read_functions_from_file("src/autons_maker.cpp")

# Load the image for the functions menu button
menu_button_image = pygame.image.load("pythonatuothing\\images\\autonsmenu.png").convert_alpha()
menu_button_rect = menu_button_image.get_rect(topleft=(10, screen.get_height() - 60))

# Load the image for the play button
play_button_image = pygame.image.load("pythonatuothing\\images\\playbuttonn.png").convert_alpha()
play_button_rect = play_button_image.get_rect(topleft=(menu_button_rect.right + 10, screen.get_height() - 60))

# Load the image for the stop button
stop_button_image = pygame.image.load("pythonatuothing\\images\\stopbutton.png").convert_alpha()
stop_button_rect = stop_button_image.get_rect(topleft=(menu_button_rect.right + 10, screen.get_height() - 360))  # Position above the play button

# Load the image for the quick save button
quick_save_button_image = pygame.image.load("pythonatuothing\\images\\quicksavebutton.png").convert_alpha()
quick_save_button_rect = quick_save_button_image.get_rect(topleft=(menu_button_rect.right + 10, screen.get_height() - 120))  # Position above the play button

# Load the image for the add position button
add_position_button_image = pygame.image.load("pythonatuothing\\images\\add_position_button.png").convert_alpha()
add_position_button_rect = add_position_button_image.get_rect(topleft=(10, screen.get_height() - 120))  # Ensure the button is positioned correctly

# Load the image for the add position button
add_zero_button_image = pygame.image.load("pythonatuothing\\images\\add_zero_button.png").convert_alpha()
add_zero_button_rect = add_zero_button_image.get_rect(topleft=(70, screen.get_height() - 180))  # Ensure the button is positioned correctly

# Load the image for the add reload button
add_reload_button_image = pygame.image.load("pythonatuothing\\images\\add_reload_button.png").convert_alpha()
add_reload_button_rect = add_reload_button_image.get_rect(topleft=(70, screen.get_height() - 240))  # Ensure the button is positioned correctly

# Load the image for the arm button
arm_button_image = pygame.image.load("pythonatuothing\\images\\arm_button.png").convert_alpha()
arm_button_rect = arm_button_image.get_rect(topleft=(10, screen.get_height() - 180))

# Load the image for the piston11 button
piston11_button_image = pygame.image.load("pythonatuothing\\images\\piston11_button.png").convert_alpha()
piston11_button_rect = piston11_button_image.get_rect(topleft=(10, screen.get_height() - 240))

# Load the image for the piston22 button
piston22_button_image = pygame.image.load("pythonatuothing\\images\\piston22_button.png").convert_alpha()
piston22_button_rect = piston22_button_image.get_rect(topleft=(10, screen.get_height() - 300))

# Load the image for the intake button
intake_button_image = pygame.image.load("pythonatuothing\\images\\intake_button.png").convert_alpha()
intake_button_rect = intake_button_image.get_rect(topleft=(10, screen.get_height() - 360))

# Variable to track the selected entry in the combined list
selected_entry_index = -1

loaded_function_name = ""

# Variable to track the state of piston11
piston11_state = False

# Variable to track the state of piston22
piston22_state = False

# List to store the points for drawing lines during playback
playback_line_points = []

def draw_lines(screen, points):
    if len(points) > 1:
        pygame.draw.lines(screen, (0, 255, 0), False, points, 2)

def draw_text_box(screen, text):
    pygame.draw.rect(screen, (0, 0, 0), (10, screen.get_height() - 50, 200, 40))
    pygame.draw.rect(screen, (255, 255, 255), (10, screen.get_height() - 50, 200, 40), 2)
    text_surface = font.render(text, True, (255, 255, 255))
    screen.blit(text_surface, (15, screen.get_height() - 45))

def replace_combined_list_with_function(function_name, functions, combined_list):
    global loaded_function_name
    if function_name in functions:
        combined_list.clear()
        combined_list.extend(functions[function_name])
        loaded_function_name = function_name

def interpolate(start, end, t):
    return start + (end - start) * t

def playback_combined_list(combined_list, player_pos, player_angle, dt):
    original_pos = player_pos.copy()  # Store the original position
    original_angle = player_angle  # Store the original angle
    
    for index, entry in enumerate(combined_list):
        if entry.startswith("// Position:"):
            parts = entry.split(", ")
            x = int(parts[0].split(": ")[1])
            y = int(parts[1])
            try:
                angle = -(360 - int(parts[2].split(": ")[1].replace("°", "").replace("ï¿½", ""))) % 360  # Ensure angle is positive
            except ValueError:
                angle = 0  # Default to 0 if there's an error
            target_pos = pygame.Vector2(x, y)
            target_angle = angle
            while player_pos.distance_to(target_pos) > 1 or abs((player_angle - target_angle + 180) % 360 - 180) > 1:
                player_pos = interpolate(player_pos, target_pos, dt)
                player_angle = interpolate_angle(player_angle, target_angle, dt)
                playback_line_points.append(player_pos.copy())  # Store the point for drawing lines
                yield player_pos, player_angle, index
            player_pos = target_pos  # Ensure the player position is exactly at the target position
            player_angle = target_angle
            pygame.time.wait(1500)  # Wait for 500 milliseconds before moving to the next entry
            angle_offset = 0
            continue  # Move to the next entry 
        elif "//set zero" in entry:
            try:
                angle_offset = int(entry.split("(")[1].split(")")[0])  # Get the angle from the entry
            except ValueError:
                angle_offset = int(entry.split("(")[1].split(",")[0])  # Handle entries with additional parameters
            
        elif "chassis.pid_drive_set" in entry:
            distance = float(entry.split("(")[1].split("_")[0]) * (30 / 7)
            direction = pygame.Vector2(1, 0).rotate(player_angle)  # Use positive angle for direction
            target_pos = player_pos + direction * distance
            while player_pos.distance_to(target_pos) > 1:
                player_pos = interpolate(player_pos, target_pos, dt)
                playback_line_points.append(player_pos.copy())  # Store the point for drawing lines
                yield player_pos, player_angle, index
            player_pos = target_pos  # Ensure the player position is exactly at the target position
        elif "chassis.pid_turn_set" in entry:
            try:
                angle = int(entry.split("(")[1].split("_")[0])  # Get the angle from the entry
            except ValueError:
                angle = int(entry.split("(")[1].split(",")[0])  # Handle entries with additional parameters
            target_angle = angle - angle_offset  # Set the target angle directly
            while abs((player_angle - target_angle + 180) % 360 - 180) > 1:
                player_angle = interpolate_angle(player_angle, target_angle, dt)
                playback_line_points.append(player_pos.copy())  # Store the point for drawing lines
                yield player_pos, player_angle, index
            player_angle = target_angle  # Ensure the player angle is exactly at the target angle
        elif "intake2" in entry:
            intake_state = int(entry.split("(")[1].split(")")[0])
            yield player_pos, player_angle, index
        elif "armPID.target_set" in entry:
            arm_pos = int(entry.split("(")[1].split(")")[0])
            yield player_pos, player_angle, index
        elif "piston11.set" in entry:
            piston11_state = "true" in entry
            yield player_pos, player_angle, index
        elif "piston22.set" in entry:
            piston22_state = "true" in entry
            yield player_pos, player_angle, index
        # Add delay or animation if needed
    player_pos = original_pos  # Restore the original position after playback
    player_angle = original_angle  # Restore the original angle after playback

def interpolate_angle(start, end, t):
    delta = (end - start + 180) % 360 - 180
    return start + delta * t * 1  # Increase the factor for faster interpolation

# Variable to track if playback is active
playback_active = False
playback_generator = None
current_step_index = -1

screen.fill("gray")
while running:
    # poll for events
    # pygame.QUIT event means the user clicked X to close your window
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            print("Quitting...")
            running = False
        elif event.type == pygame.MOUSEBUTTONDOWN and not menu_open:
            if event.button == 1:  # Left click
                # Add point to line points list
                if menu_button_rect.collidepoint(event.pos):
                    print("Opening menu...")
                    selected_function = display_function_menu(screen, font, functions)
                    if selected_function:
                        print(f"Selected function: {selected_function}")
                        replace_combined_list_with_function(selected_function, functions, combined_list)
                        print("Combined list replaced with selected function")
                elif play_button_rect.collidepoint(event.pos):
                    playback_active = True
                    playback_generator = playback_combined_list(combined_list, player_pos, player_angle, dt)
                    print("Playback started")
                elif stop_button_rect.collidepoint(event.pos):
                    playback_active = False
                    playback_generator = None
                    current_step_index = -1
                    print("Playback stopped")
                elif quick_save_button_rect.collidepoint(event.pos):
                    if loaded_function_name:
                        write_to_filef(event, combined_list, TRUE, screen, font, pygame, loaded_function_name)
                    else:
                        selected_function = display_function_menu(screen, font, functions)
                        if selected_function:
                            loaded_function_name = selected_function
                            write_to_filef(event, combined_list, TRUE, screen, font, pygame, loaded_function_name)
                    print("Quick save completed")
                elif add_position_button_rect.collidepoint(event.pos):
                    position_entry = f"// Position: {int(player_pos.x)}, {int(player_pos.y)}, Angle: {int(player_angle) % 360}°"
                    if combined_list and combined_list[selected_entry_index] == "// New entry":
                        combined_list[selected_entry_index] = position_entry
                    else:
                        combined_list.append(position_entry)
                    print(f"Added position to combined list: {combined_list[-1]}")
                elif add_zero_button_rect.collidepoint(event.pos):
                    zero_entry = f"//set angle ({int(player_angle) % 360})"
                    if combined_list and combined_list[selected_entry_index] == "// New entry":
                        combined_list[selected_entry_index] = zero_entry
                    else:
                        combined_list.append(zero_entry)
                    print(f"Added position to combined list: {combined_list[-1]}")
                elif arm_button_rect.collidepoint(event.pos):
                    arm_pos = (arm_pos + 1) % 4  # Cycle through 4 states
                    arm_positions = [10, 290, 550, 1850]
                    arm_pos = arm_positions[arm_pos]
                    combined_list.append(f"armPID.target_set({arm_pos});")
                    print(f"Arm position set to: {arm_pos}")
                elif piston11_button_rect.collidepoint(event.pos):
                    piston11_state = not piston11_state
                    combined_list.append(f"piston11.set({str(piston11_state).lower()});")
                    print(f"Piston11 state set to: {piston11_state}")
                elif piston22_button_rect.collidepoint(event.pos):
                    piston22_state = not piston22_state
                    combined_list.append(f"piston22.set({str(piston22_state).lower()});")
                    print(f"Piston22 state set to: {piston22_state}")
                elif intake_button_rect.collidepoint(event.pos):
                    intake_state = (intake_state + 1) % 3  # Cycle through 3 states
                    intake_states = [0, 127, -127]
                    intake_state = intake_states[intake_state]
                    combined_list.append(f"intake2.move({intake_state});")
                    print(f"Intake state set to: {intake_state}")
                elif add_reload_button_rect.collidepoint(event.pos):
                    functions = read_functions_from_file("src/autons_maker.cpp")
                    print("Functions reloaded")
            elif event.button == 3:  # Right click
                # Move player to mouse position
                player_pos = pygame.Vector2(event.pos) + camera_offset
        elif event.type == pygame.MOUSEBUTTONDOWN:
            if menu_button_rect.collidepoint(event.pos):
                print("Opening menu...")
                selected_function = display_function_menu(screen, font, functions)
                if selected_function:
                    print(f"Selected function: {selected_function}")
                    replace_combined_list_with_function(selected_function, functions, combined_list)
                    print("Combined list replaced with selected function")
        elif event.type == pygame.MOUSEWHEEL and not menu_open:
            # Zoom in and out or scroll the list
            mouse_x, mouse_y = pygame.mouse.get_pos()
            mouse_pos = pygame.Vector2(mouse_x, mouse_y)
            if pygame.key.get_mods() & pygame.KMOD_CTRL:
                if event.y > 0:
                    zoom_factor *= 1.1
                    camera_offset += (mouse_pos - camera_offset) * (1 - 1 / 1.1)
                elif event.y < 0:
                    zoom_factor /= 1.1
                    camera_offset -= (mouse_pos - camera_offset) * (1 - 1.1)
            else:
                scroll_offset += event.y * 20
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE:
                menu_open = not menu_open
            elif not menu_open:
                if event.key == pygame.K_z:
                    text_box_open = not text_box_open
                    input_angle = ""
                elif text_box_open:
                    if event.key == pygame.K_RETURN:
                        try:
                            player_angle = float(input_angle)
                        except ValueError:
                            pass
                        text_box_open = False
                    elif event.key == pygame.K_BACKSPACE:
                        input_angle = input_angle[:-1]
                    else:
                        input_angle += event.unicode
                else:
                    if event.key == pygame.K_j and initial_player_pos is not None:
                        direction = pygame.Vector2(1, 0).rotate(-player_angle)
                        distance = direction.dot(player_pos - initial_player_pos) / zoom_factor / (30/7)
                        if not combined_list:
                            combined_list.append(f"// Position: {int(player_pos.x)}, {int(player_pos.y)}, Angle: {int(player_angle) % 360}°\n")
                        if combined_list and combined_list[selected_entry_index] == "// New entry":
                            combined_list[selected_entry_index] = f"chassis.pid_drive_set({int(distance)}_in, 110);\nchassis.pid_wait();\n"
                        else:
                            combined_list.append(f"chassis.pid_drive_set({int(distance)}_in, 110);\nchassis.pid_wait();\n")
                        print(f"Distance: {int(distance)}")
                    elif event.key == pygame.K_h:
                        angle = int(player_angle) % 360
                        if not combined_list:
                            combined_list.append(f"// Position: {int(player_pos.x)}, {int(player_pos.y)}, Angle: {int(player_angle) % 360}°\n")
                        if combined_list and combined_list[selected_entry_index] == "// New entry":
                            combined_list[selected_entry_index] = f"chassis.pid_turn_set({angle}_deg, 90);\nchassis.pid_wait();\n"
                        else:
                            combined_list.append(f"chassis.pid_turn_set({angle}_deg, 90);\nchassis.pid_wait();\n")
                        print(f"chassis.pid_turn_set({angle}_deg, 90);\nchassis.pid_wait();\n")
                    elif event.key == pygame.K_COMMA:
                        #intake on
                        intake_state = 127
                        if not combined_list:
                            combined_list.append(f"// Position: {int(player_pos.x)}, {int(player_pos.y)}, Angle: {int(player_angle) % 360}°\n")
                        if combined_list and combined_list[selected_entry_index] == "// New entry":
                            combined_list[selected_entry_index] = f"2(127);\n"
                        else:
                            combined_list.append(f"2(127);\n")
                        print(f"2(127);")
                    elif event.key == pygame.K_PERIOD:
                        #intake off
                        intake_state = 0
                        if not combined_list:
                            combined_list.append(f"// Position: {int(player_pos.x)}, {int(player_pos.y)}, Angle: {int(player_angle) % 360}°\n")
                        if combined_list and combined_list[selected_entry_index] == "// New entry":
                            combined_list[selected_entry_index] = f"2(0);\n"
                        else:
                            combined_list.append(f"2(0);\n")
                        print(f"2(0);")
                    elif event.key == pygame.K_SLASH:
                        #intake reverse
                        intake_state = -127
                        if not combined_list:
                            combined_list.append(f"// Position: {int(player_pos.x)}, {int(player_pos.y)}, Angle: {int(player_angle) % 360}°\n")
                        if combined_list and combined_list[selected_entry_index] == "// New entry":
                            combined_list[selected_entry_index] = f"2(-127);\n"
                        else:
                            combined_list.append(f"2(-127);\n")
                        print(f"2(-127);")
                    elif event.key == pygame.K_v:
                        arm_pos = 10
                        if not combined_list:
                            combined_list.append(f"// Position: {int(player_pos.x)}, {int(player_pos.y)}, Angle: {int(player_angle) % 360}°\n")
                        if combined_list and combined_list[selected_entry_index] == "// New entry":
                            combined_list[selected_entry_index] = f"armPID.target_set({arm_pos});\n"
                        else:
                            combined_list.append(f"armPID.target_set({arm_pos});\n")
                        print(f"armPID.target_set({arm_pos});")
                    elif event.key == pygame.K_b:
                        arm_pos = 290
                        if not combined_list:
                            combined_list.append(f"// Position: {int(player_pos.x)}, {int(player_pos.y)}, Angle: {int(player_angle) % 360}°\n")
                        if combined_list and combined_list[selected_entry_index] == "// New entry":
                            combined_list[selected_entry_index] = f"armPID.target_set({arm_pos});\n"
                        else:
                            combined_list.append(f"armPID.target_set({arm_pos});\n")
                        print(f"armPID.target_set({arm_pos});")
                    elif event.key == pygame.K_n:
                        arm_pos = 1850
                        if not combined_list:
                            combined_list.append(f"// Position: {int(player_pos.x)}, {int(player_pos.y)}, Angle: {int(player_angle) % 360}°\n")
                        if combined_list and combined_list[selected_entry_index] == "// New entry":
                            combined_list[selected_entry_index] = f"armPID.target_set({arm_pos});\n"
                        else:
                            combined_list.append(f"armPID.target_set({arm_pos});\n")
                        print(f"armPID.target_set({arm_pos});")
                    elif event.key == pygame.K_m:
                        arm_pos = 550
                        if not combined_list:
                            combined_list.append(f"// Position: {int(player_pos.x)}, {int(player_pos.y)}, Angle: {int(player_angle) % 360}°\n")
                        if combined_list and combined_list[selected_entry_index] == "// New entry":
                            combined_list[selected_entry_index] = f"armPID.target_set({arm_pos});\n"
                        else:
                            combined_list.append(f"armPID.target_set({arm_pos});\n")
                        print(f"armPID.target_set({arm_pos});")
                    elif event.key == pygame.K_u:
                        mode = "place"
                        print("Mode: Place")
                    elif event.key == pygame.K_i:
                        mode = "set"
                        print("Mode: Set")
                    elif event.key == pygame.K_l:
                        line_drawing_mode = not line_drawing_mode
                        if line_drawing_mode:
                            line_start_pos = player_pos.copy()
                            initial_player_pos = player_pos.copy()  # Store the initial player position
                        else:
                            line_start_pos = None
                            initial_player_pos = None  # Reset the initial player position
                        print(f"Line Drawing Mode: {'On' if line_drawing_mode else 'Off'}")
                    elif event.key == pygame.K_c:
                        combined_list.clear()
                        selected_entry_index = -1  # Reset the selected entry index
                        print("Combined list cleared")
                    elif event.key == pygame.K_BACKSPACE:
                        if combined_list:
                            combined_list.pop()
                            selected_entry_index = max(selected_entry_index - 1, -1)  # Update the selected entry index
                            print("Last entry deleted")
                    elif event.key == pygame.K_p:
                        write_to_filef(event, combined_list, True, screen, font, pygame, loaded_function_name)
                    elif event.key == pygame.K_e:
                        selected_function = display_function_menu(screen, font, functions)
                        if selected_function:
                            print(f"Selected function: {selected_function}")
                            replace_combined_list_with_function(selected_function, functions, combined_list)
                            print("Combined list replaced with selected function")
                    elif event.key in [pygame.K_1, pygame.K_2, pygame.K_3, pygame.K_4, pygame.K_5, pygame.K_6, pygame.K_7, pygame.K_8, pygame.K_9, pygame.K_0]:
                        key = event.key - pygame.K_0
                        if mode == "place":
                            saved_positions[key] = (player_pos.copy(), player_angle)
                            print(f"Position {key} saved: {saved_positions[key]}")
                        elif mode == "set" and key in saved_positions:
                            player_pos, player_angle = saved_positions[key]
                            print(f"Moved to position {key}: {player_pos}, Angle: {player_angle}")
                    elif event.key == pygame.K_LEFTBRACKET:
                        if combined_list:
                            selected_entry_index = (selected_entry_index - 1) % len(combined_list)
                            print(f"Selected entry index: {selected_entry_index}")
                    elif event.key == pygame.K_RIGHTBRACKET:
                        if combined_list:
                            selected_entry_index = (selected_entry_index + 1) % len(combined_list)
                            print(f"Selected entry index: {selected_entry_index}")
                    elif event.key == pygame.K_DELETE:
                        if combined_list and selected_entry_index != -1:
                            combined_list.pop(selected_entry_index)
                            if not combined_list:
                                selected_entry_index = -1
                            else:
                                selected_entry_index %= len(combined_list)
                            print(f"Deleted entry at index: {selected_entry_index}")
                    elif event.key == pygame.K_INSERT:
                        if combined_list and selected_entry_index != -1:
                            combined_list.insert(selected_entry_index + 1, "// New entry")
                            selected_entry_index += 1
                            print(f"Inserted new entry at index: {selected_entry_index}")
                    elif event.key == pygame.K_r:
                        piston22_state = not piston22_state
                        combined_list.append(f"piston22.set({str(piston22_state).lower()});")
                        print(f"piston22.set({str(piston22_state).lower()});")
                    elif pygame.key.get_mods():
                        if event.key == pygame.K_j and initial_player_pos is not None:
                            direction = pygame.Vector2(1, 0).rotate(-player_angle)
                            distance = direction.dot(player_pos - initial_player_pos) / zoom_factor / (30/7)
                            if not combined_list:
                                combined_list.append(f"// Position: {int(player_pos.x)}, {int(player_pos.y)}, Angle: {int(player_angle) % 360}°\n")
                            if combined_list[selected_entry_index] == "// New entry":
                                combined_list[selected_entry_index] = f"chassis.pid_drive_set({int(distance)}_in, 110);\nchassis.pid_wait();\n"
                            else:
                                combined_list.insert(selected_entry_index + 1, f"chassis.pid_drive_set({int(distance)}_in, 110);\nchassis.pid_wait();\n")
                                selected_entry_index += 1
                            print(f"Distance: {int(distance)}")
                        elif event.key == pygame.K_h:
                            angle = int(player_angle) % 360
                            if not combined_list:
                                combined_list.append(f"// Position: {int(player_pos.x)}, {int(player_pos.y)}, Angle: {int(player_angle) % 360}°\n")
                            if combined_list[selected_entry_index] == "// New entry":
                                combined_list[selected_entry_index] = f"chassis.pid_turn_set({angle}_deg, 90);\nchassis.pid_wait();\n"
                            else:
                                combined_list.insert(selected_entry_index + 1, f"chassis.pid_turn_set({angle}_deg, 90);\nchassis.pid_wait();\n")
                                selected_entry_index += 1
                            print(f"chassis.pid_turn_set({angle}_deg, 90);\nchassis.pid_wait();\n")
                        elif event.key == pygame.K_COMMA:
                            #intake on
                            intake_state = 127
                            if not combined_list:
                                combined_list.append(f"// Position: {int(player_pos.x)}, {int(player_pos.y)}, Angle: {int(player_angle) % 360}°\n")
                            if combined_list[selected_entry_index] == "// New entry":
                                combined_list[selected_entry_index] = f"2(127);\n"
                            else:
                                combined_list.insert(selected_entry_index + 1, f"2(127);\n")
                                selected_entry_index += 1
                            print(f"2(127);")
                        elif event.key == pygame.K_PERIOD:
                            #intake off
                            intake_state = 0
                            if not combined_list:
                                combined_list.append(f"// Position: {int(player_pos.x)}, {int(player_pos.y)}, Angle: {int(player_angle) % 360}°\n")
                            if combined_list[selected_entry_index] == "// New entry":
                                combined_list[selected_entry_index] = f"2(0);\n"
                            else:
                                combined_list.insert(selected_entry_index + 1, f"2(0);\n")
                                selected_entry_index += 1
                            print(f"2(0);")
                        elif event.key == pygame.K_SLASH:
                            #intake reverse
                            intake_state = -127
                            if not combined_list:
                                combined_list.append(f"// Position: {int(player_pos.x)}, {int(player_pos.y)}, Angle: {int(player_angle) % 360}°\n")
                            if combined_list[selected_entry_index] == "// New entry":
                                combined_list[selected_entry_index] = f"2(-127);\n"
                            else:
                                combined_list.insert(selected_entry_index + 1, f"2(-127);\n")
                                selected_entry_index += 1
                            print(f"2(-127);")
                        elif event.key == pygame.K_v:
                            arm_pos = 10
                            if not combined_list:
                                combined_list.append(f"// Position: {int(player_pos.x)}, {int(player_pos.y)}, Angle: {int(player_angle) % 360}°\n")
                            if combined_list[selected_entry_index] == "// New entry":
                                combined_list[selected_entry_index] = f"armPID.target_set({arm_pos});\n"
                            else:
                                combined_list.insert(selected_entry_index + 1, f"armPID.target_set({arm_pos});\n")
                                selected_entry_index += 1
                            print(f"armPID.target_set({arm_pos});")
                        elif event.key == pygame.K_b:
                            arm_pos = 290
                            if not combined_list:
                                combined_list.append(f"// Position: {int(player_pos.x)}, {int(player_pos.y)}, Angle: {int(player_angle) % 360}°\n")
                            if combined_list[selected_entry_index] == "// New entry":
                                combined_list[selected_entry_index] = f"armPID.target_set({arm_pos});\n"
                            else:
                                combined_list.insert(selected_entry_index + 1, f"armPID.target_set({arm_pos});\n")
                                selected_entry_index += 1
                            print(f"armPID.target_set({arm_pos});")
                        elif event.key == pygame.K_n:
                            arm_pos = 1850
                            if not combined_list:
                                combined_list.append(f"// Position: {int(player_pos.x)}, {int(player_pos.y)}, Angle: {int(player_angle) % 360}°\n")
                            if combined_list[selected_entry_index] == "// New entry":
                                combined_list[selected_entry_index] = f"armPID.target_set({arm_pos});\n"
                            else:
                                combined_list.insert(selected_entry_index + 1, f"armPID.target_set({arm_pos});\n")
                                selected_entry_index += 1
                            print(f"armPID.target_set({arm_pos});")
                        elif event.key == pygame.K_m:
                            arm_pos = 550
                            if not combined_list:
                                combined_list.append(f"// Position: {int(player_pos.x)}, {int(player_pos.y)}, Angle: {int(player_angle) % 360}°\n")
                            if combined_list[selected_entry_index] == "// New entry":
                                combined_list[selected_entry_index] = f"armPID.target_set({arm_pos});\n"
                            else:
                                combined_list.insert(selected_entry_index + 1, f"armPID.target_set({arm_pos});\n")
                                selected_entry_index += 1
                            print(f"armPID.target_set({arm_pos});")

    if playback_active and playback_generator:
        try:
            player_pos, player_angle, current_step_index = next(playback_generator)
        except StopIteration:
            playback_active = False
            playback_generator = None
            current_step_index = -1
            print("Playback finished")
            player_angle = 360 - player_angle  # Invert the angle back to the original

    if not menu_open:
        # fill the screen with a color to wipe away anything from last frame
        screen.fill("gray")

        eventkey = pygame.event.get()

        # Update camera offset to center on (0, 0)
        camera_offset.x = -screen.get_width() / 2
        camera_offset.y = -screen.get_height() / 2

        # Create a new surface for the scene
        scene_surface = pygame.Surface((screen.get_width(), screen.get_height()), pygame.SRCALPHA)
        scene_surface.fill((0, 0, 0, 0))  # Make the surface transparent

        # Draw the field object with camera offset
        scene_surface.blit(field_object_image, field_object_pos - camera_offset)

        # Draw lines with camera offset
        draw_lines(scene_surface, [point - camera_offset for point in line_points])

        # Scale the scene surface based on the zoom factor
        scaled_scene_surface = pygame.transform.scale(scene_surface, (int(screen.get_width() * zoom_factor), int(screen.get_height() * zoom_factor)))
        scaled_scene_rect = scaled_scene_surface.get_rect(center=(screen.get_width() / 2, screen.get_height() / 2))

        # Draw the scaled scene surface onto the main screen
        screen.blit(scaled_scene_surface, scaled_scene_rect.topleft)

        # Scale the player image based on the zoom factor
        scaled_player_image = pygame.transform.scale(player_image, (int(player_image.get_width() * zoom_factor), int(player_image.get_height() * zoom_factor)))

        # Draw the playback lines
        if len(playback_line_points) > 1:
            pygame.draw.lines(screen, (0, 255, 0), False, [point - camera_offset for point in playback_line_points], 2)

        # Rotate the player image based on the inverted angle
        rotated_player_image = pygame.transform.rotate(scaled_player_image, 360 - player_angle)  # Adjust angle by subtracting from 360
        rotated_player_rect = rotated_player_image.get_rect(center=player_pos - camera_offset)

        # Draw the player as an image with camera offset
        screen.blit(rotated_player_image, rotated_player_rect.topleft)

        # Render the inverted angle as text in degrees
        angle_text = font.render(f"Angle: {int( player_angle) % 360}°", True, (255, 255, 255))
        screen.blit(angle_text, (10, 10))

        # Get the mouse position
        mouse_x, mouse_y = pygame.mouse.get_pos()
        mouse_text = font.render(f"Mouse: ({mouse_x}, {mouse_y})", True, (255, 255, 255))
        screen.blit(mouse_text, (10, 50))

        # Display the loaded function name at the top
        if loaded_function_name:
            loaded_function_text = font.render(f"Loaded Function: {loaded_function_name}", True, (255, 255, 255))
            screen.blit(loaded_function_text, (screen.get_width() / 2 - loaded_function_text.get_width() / 2, 25))

        # Display the initial player position when L is first pressed
        if initial_player_pos is not None:
            initial_pos_text = font.render(f"Initial Pos: ({int(initial_player_pos.x)}, {int(initial_player_pos.y)})", True, (255, 255, 255))
            screen.blit(initial_pos_text, (10, 90))

            direction = pygame.Vector2(1, 0).rotate(-player_angle)
            distance = direction.dot(player_pos - initial_player_pos) / zoom_factor / (30/7)  # Calculate the distance between the initial and current player position
            distance_text = font.render(f"Distance: {int(distance)}", True, (255, 255, 255))
            screen.blit(distance_text, (10, 130))

        # Display the intake state
        intake_text = font.render(f"Intake State: {intake_state}", True, (255, 255, 255))
        screen.blit(intake_text, (10, 170))

        # Display the arm position
        arm_pos_text = font.render(f"Arm Pos: {arm_pos}", True, (255, 255, 255))
        screen.blit(arm_pos_text, (10, 200))

        # Display the piston11 state
        piston11_text = font.render(f"Piston11 State: {piston11_state}", True, (255, 255, 255))
        screen.blit(piston11_text, (10, 230))

        # Display the piston22 state
        piston22_text = font.render(f"Piston22 State: {piston22_state}", True, (255, 255, 255))
        screen.blit(piston22_text, (10, 260))

        # Display the combined list of distances and angles on the right side of the screen
        list_start_y = 10  # Starting y position for the list
        list_end_y = screen.get_height() - 20  # Ending y position to avoid overlap with bottom content
        for i, entry in enumerate(combined_list):
            entry_y = list_start_y + i * 20 + scroll_offset
            if entry_y < list_end_y:
                color = (255, 255, 255) if i != current_step_index else (0, 255, 0)
                if i == selected_entry_index:
                    color = (255, 0, 0)  # Highlight the selected entry in red
                entry_text = font.render(entry, True, color)
                screen.blit(entry_text, (screen.get_width() - 350, entry_y))

        # Display the saved positions and angles on the middle left side of the screen
        saved_list_start_y = screen.get_height() // 2 - len(saved_positions) * 10  # Center the saved positions list vertically
        for key, (pos, angle) in saved_positions.items():
            pos_text = font.render(f"{key}: ({int(pos.x)}, {int(pos.y)}), Angle: {int(angle)}°", True, (255, 255, 255))
            screen.blit(pos_text, (10, saved_list_start_y + key * 20))

        # Display the current mode at the top
        mode_text = font.render(f"Mode: {mode.capitalize()}", True, (255, 255, 255))
        screen.blit(mode_text, (screen.get_width() / 2 - mode_text.get_width() / 2, 10))

        # Draw the text box if open
        if text_box_open:
            1
            #draw_text_box(screen, input_function, font)

        # Draw the functions menu button
        screen.blit(menu_button_image, menu_button_rect.topleft)

        # Draw the play button
        screen.blit(play_button_image, play_button_rect.topleft)

        # Draw the stop button
        screen.blit(stop_button_image, stop_button_rect.topleft)

        # Draw the quick save button
        screen.blit(quick_save_button_image, quick_save_button_rect.topleft)

        # Draw the add position button
        screen.blit(add_position_button_image, add_position_button_rect.topleft)

         # Draw the add position button
        screen.blit(add_zero_button_image, add_zero_button_rect.topleft)

        screen.blit(add_reload_button_image, add_reload_button_rect.topleft)

        # Draw the arm button
        screen.blit(arm_button_image, arm_button_rect.topleft)

        # Draw the piston11 button
        screen.blit(piston11_button_image, piston11_button_rect.topleft)

        # Draw the piston22 button
        screen.blit(piston22_button_image, piston22_button_rect.topleft)

        # Draw the intake button
        screen.blit(intake_button_image, intake_button_rect.topleft)

        # Handle player movement
        keys = pygame.key.get_pressed()
        if line_drawing_mode:
            direction = pygame.Vector2(1, 0).rotate(player_angle)  # Use positive angle for direction
            direction = direction.normalize()  # Normalize the direction vector
            line_end_pos = line_start_pos + direction * 10000  # Extend the line far enough to reach the screen boundaries
            line_start_extended = line_start_pos - direction * 10000
            pygame.draw.line(screen, (255, 0, 0), line_start_extended - camera_offset, line_end_pos - camera_offset, 2)
            if keys[pygame.K_w]:
                player_pos = player_pos + direction * (300 * dt)
            if keys[pygame.K_s]:
                player_pos = player_pos - direction * (300 * dt)
            if keys[pygame.K_UP]:
                player_pos = player_pos + direction * (50 * dt)
            if keys[pygame.K_DOWN]:
                player_pos = player_pos - direction * (50 * dt)
        else:
            if keys[pygame.K_w]:
                player_pos += pygame.Vector2(1, 0).rotate(player_angle) * (300 * dt)  # Adjust angle by 180 degrees
            if keys[pygame.K_s]:
                player_pos -= pygame.Vector2(1, 0).rotate(player_angle) * (300 * dt)  # Adjust angle by 180 degrees
            if keys[pygame.K_a]:
                player_angle += 300 * dt  # Rotate counterclockwise
            if keys[pygame.K_d]:
                player_angle -= 300 * dt  # Rotate clockwise

        if not line_drawing_mode:
            if keys[pygame.K_q]:
                player_pos -= pygame.Vector2(1, 0).rotate(player_angle + 90) * (300 * dt)  # Adjust angle by 180 degrees
            if keys[pygame.K_e]:
                player_pos += pygame.Vector2(1, 0).rotate(player_angle + 90) * (300 * dt)  # Adjust angle by 180 degrees
            if keys[pygame.K_UP]:
                player_pos += pygame.Vector2(1, 0).rotate(player_angle) * (100 * dt)  # Move forward slowly, adjust angle by 180 degrees
            if keys[pygame.K_DOWN]:
                player_pos -= pygame.Vector2(1, 0).rotate(player_angle) * (100 * dt)  # Move backward slowly, adjust angle by 180 degrees
            if keys[pygame.K_LEFT]:
                player_angle += 50 * dt
            if keys[pygame.K_RIGHT]:
                player_angle -= 50 * dt
            if keys[pygame.K_x]:
                playback_line_points.clear()  # Clear the playback lines
                print("Playback lines cleared")
    else:
        # Draw a blurred version of the game
        blurred_surface = pygame.Surface(screen.get_size(), pygame.SRCALPHA)
        blurred_surface.fill((0, 30, 30, 127))  # Semi-transparent overlay
        screen.blit(blurred_surface, (0, 0))
        draw_menu(screen, font)

    # flip() the display to put your work on screen
    pygame.display.flip()

    # limits FPS to 60
    # dt is delta time in seconds since last frame, used for framerate-
    # independent physics.
    dt = clock.tick(60) / 1000

pygame.quit()