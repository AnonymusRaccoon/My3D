/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** runner
*/

#pragma once

#define ERROR 84
#include "scene.h"

int start_game();

bool start_button(gc_engine *engine, int entity_id);
bool options(gc_engine *engine, int entity_id);
bool goto_main_menu(gc_engine *engine, int entity_id);
bool quit(gc_engine *engine, int entity_id);

bool fullscreen(gc_engine *engine, int entity_id);