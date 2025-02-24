import pygame

def read_functions_from_file(filepath):
    functions = {}
    current_function = None
    with open(filepath, "r") as file:
        for line in file:
            line = line.strip()
            if line.startswith("void"):
                current_function = line.split()[1].strip("(){")
                functions[current_function] = []
            elif current_function:
                functions[current_function].append(line)
                if line == "}//end":
                    current_function = None
    return functions

def display_function_menu(screen, font, functions):
    menu_open = True
    selected_function = None
    function_names = list(functions.keys())
    selected_index = 0

    while menu_open:
        screen.fill((0, 0, 0, 0))  # Make the background transparent
        y_offset = 50
        for i, function_name in enumerate(function_names):
            color = (255, 255, 255) if i != selected_index else (255, 0, 0)
            text_surface = font.render(function_name, True, color)
            screen.blit(text_surface, (50, y_offset))
            y_offset += 40

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                menu_open = False
                pygame.quit()
                quit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    menu_open = False
                elif event.key == pygame.K_RETURN:
                    selected_function = function_names[selected_index]
                    menu_open = False
                elif event.key == pygame.K_UP:
                    selected_index = (selected_index - 1) % len(function_names)
                elif event.key == pygame.K_DOWN:
                    selected_index = (selected_index + 1) % len(function_names)

        pygame.display.flip()
    return selected_function
