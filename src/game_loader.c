/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** game_loader
*/

#include "engine.h"
#include "setup.h"
#include <SFML/System.h>

void test(gc_engine *engine, int entity_id);

int register_customcmps(gc_engine *engine)
{
    engine->finish_physics(engine);
	engine->add_callback(engine, "test", &test);
    return (0);
}


int create_game_scene(gc_engine *engine)
{
    gc_scene *scene;

    register_customcmps(engine);
    scene = scene_create(engine, "prefabs/mainmenu.gcprefab");
    if (!scene)
        return (-1);
    engine->change_scene(engine, scene);
    return (0);
}

int start_game()
{
    gc_engine *engine = engine_create();
    sfClock *clock = sfClock_create();

    if (!engine || engine_use_sfml(engine, "DPR tycoon", 60) < 0)
        return (ERROR);
    if (create_game_scene(engine) < 0)
        return (ERROR);
    while (engine->is_open(engine))
        engine->game_loop(engine, sfTime_asSeconds(sfClock_restart(clock)));
    engine->destroy(engine);
    sfClock_destroy(clock);
    return (0);
}