import pygame
from pygame import font


def draw_menu(screen, font):
    menu_text = [
        "Key Bindings:",
        "• W - Move forward",
        "• S - Move backward",
        "• A - Move left",
        "• D - Move right",
        "• Q - Rotate counterclockwise",
        "• E - Rotate clockwise",
        "• UP - Move forward slowly",
        "• DOWN - Move backward slowly",
        "• LEFT - Move left slowly",
        "• RIGHT - Move right slowly",
        "• L - Toggle line drawing mode",
        "• C - Clear combined list",
        "• Backspace - Delete last entry",
        "• 1-0 - Save/Set positions",
        "• Esc - Close menu",
        "• P - Print combined list",
        "• Right Click - Move player to mouse",
        "• Z - Open text box to set angle",
        "• J - Add distance to combined list",
        "• H - Add angle to combined list",
        "• Comma - Intake on",
        "• Period - Intake off",
        "• Slash - Intake reverse",
        "• V - Set arm position to 10",
        "• B - Set arm position to 290",
        "• N - Set arm position to 1850",
        "• M - Set arm position to 550",
        "• U - Set mode to place",
        "• I - Set mode to set"
    ]
    for i, text in enumerate(menu_text):
        menu_item = font.render(text, True, (255, 255, 255))
        screen.blit(menu_item, (screen.get_width() / 2 - menu_item.get_width() / 2, 100 + i * 30))
