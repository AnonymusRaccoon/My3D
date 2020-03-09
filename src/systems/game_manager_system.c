//
// Created by anonymus-raccoon on 3/9/20.
//

#include "system.h"
#include "components/game_manager.h"
#include "prefab.h"

static void update_entity(gc_engine *engine, void *system, gc_entity *entity, \
float dtime)
{
	struct game_manager *manager = GETCMP(entity, game_manager);
	gc_scene *gameover_scene = NULL;

	if (manager->happiness <= 0)
		gameover_scene = scene_create(engine, "prefabs/go/happiness.gcprefab");
	if (manager->stupidity >= 100)
		gameover_scene = scene_create(engine, "prefabs/go/stupidity.gcprefab");

	if (gameover_scene)
		engine->change_scene(engine, gameover_scene);
}


static void destroy(void *system)
{
	(void)system;
}

const gc_system game_manager_system = {
	name: "game_cycle",
	component_name: "game_manager",
	size: sizeof(gc_system),
	ctr: NULL,
	dtr: NULL,
	check_dependencies: &system_check_dependencies,
	update_entity: &update_entity,
	destroy: &destroy
};