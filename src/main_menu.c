//
// Created by anonymus-raccoon on 2/24/20.
//

#include "engine.h"
#include "scene.h"
#include "my.h"

bool start_button(gc_engine *engine, int entity_id)
{
	gc_scene *scene = scene_create(engine, "prefabs/game.gcprefab");
	if (!scene) {
		engine->should_close = true;
		my_printf("The game scene couldn't be found.\n");
	}
	engine->change_scene(engine, scene);
	return (true);
}

bool quit(gc_engine *engine, int entity_id)
{
	engine->should_close = true;
	return (true);
}