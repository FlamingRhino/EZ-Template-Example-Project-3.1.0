import pygame
from pygame import font
input_function = ""

def write_to_filef(event, combined_list, text_box_open, screen, font, pygame, function_name):
    input_pathname = "src/autons_maker.cpp"
    input_function = function_name if function_name else ""
    
    while text_box_open:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                text_box_open = False
                pygame.quit()
                quit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN:
                    if not function_name:
                        input_function = "void " + input_function + "(){"
                    else:
                        input_function = "void " + function_name + "(){"
                    with open(input_pathname, "r") as file:
                        lines = file.readlines()
                    
                    found_function = False
                    with open(input_pathname, "w") as file:
                        skip_lines = False
                        for line in lines:
                            if input_function in line:
                                found_function = True
                                skip_lines = True
                                file.write(line)
                                for item in combined_list:
                                    if item != "}//end":
                                        file.write(item + "\n")
                                file.write("}//end\n")
                            elif skip_lines and "}//end" in line:
                                skip_lines = False
                            elif not skip_lines:
                                file.write(line)
                        
                        if not found_function:
                            file.write(input_function + "\n")
                            for item in combined_list:
                                if item != "}//end":
                                    file.write(item + "\n")
                            file.write("}//end\n")
                    
                    for item in combined_list:
                        print(item)
                    print(f"Combined list saved to {input_pathname} under function {input_function}")
                    text_box_open = False
                    print("Combined list:")
                
                elif event.key == pygame.K_BACKSPACE:
                    input_function = input_function[:-1]
                    draw_textt_box(screen, input_function, font)
                else:
                    input_function += event.unicode
                    draw_textt_box(screen, input_function, font)
                
                # Call draw_text_box to draw the text box on the screen
        draw_textt_box(screen, input_function, font)

def draw_textt_box(screen, text, font):
    pygame.draw.rect(screen, (0, 0, 0), (10, screen.get_height() - 50, 200, 40))
    pygame.draw.rect(screen, (255, 255, 255), (10, screen.get_height() - 50, 200, 40), 2)
    font = pygame.font.Font(None, 36)
    
    text_surface = font.render(f"name: {text}", True, (255, 0, 0))
    screen.blit(text_surface, (15, screen.get_height() - 50))
    pygame.display.flip()
