//
// Created by LEE32 on 2026/1/1.
//

#include "../include/input/InputHandler.h"
#include "../include/character/Character.h"
#include <iostream>

#include "skill/Skill.h"

size_t InputHandler::selectSkill(const Character &player) {
    std::cout << "\nChoose a skill:\n";

    for (size_t i = 0; i < player.getSkillCount(); i++) {
        const Skill *skill = player.getSkill(i);
        std::cout << i << ". " << skill->getName() << "(Mana: " << skill->getManaCost() << ", CD: " << skill->
                getCooldown() << ")\n";
    }

    size_t choice;
    std::cin >> choice;

    return choice;
}
