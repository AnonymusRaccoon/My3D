//
// Created by anonymus-raccoon on 3/9/20.
//

#include <components/tag_component.h>
#include "my.h"
#include "prefab.h"
#include "keybindings.h"
#include "system.h"
#include "components/game_manager.h"

static void pause_destroy(gc_scene *scene)
{
	gc_list *list = scene->get_entity_by_cmp(scene, "tag_component");

	for (gc_list *li = list; li; li = li->next ) {
		if (!my_strcmp(GETCMP(li->data, tag_component)->tag, "pause"))
			((gc_entity *)li->data)->destroy(li->data, scene);
	}
}

bool toggle_pause(gc_engine *engine, int entity_id, gc_vector2 _)
{
	if (!engine->scene->is_paused)
		prefab_load(engine, "prefabs/pause.gcprefab");
	else
		pause_destroy(engine->scene);
	engine->scene->is_paused = !engine->scene->is_paused;
	return (true);
}

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
	if (engine->is_keypressed(ESCAPE)) {
		toggle_pause(engine, 0, (gc_vector2){0, 0});
	}
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