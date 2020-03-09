//
// Created by anonymus-raccoon on 3/6/20.
//

#include <stdbool.h>
#include "components/game_manager.h"
#include <stdlib.h>
#include <components/transform_component.h>
#include "components/teams_component.h"
#include "engine.h"

bool absent_check(gc_engine *engine, int id)
{
	gc_scene *scene = engine->scene;
	gc_list *li = scene->get_entity_by_cmp(scene, "game_manager");
	gc_entity *entity = scene->get_entity(scene, id);
	float y_pos = GETCMP(entity, transform_component)->position.y;
	int prefab_id = entity->prefab_id;

	if (!li)
		return (false);
	GETCMP(li->data, game_manager)->happiness += 3;
	GETCMP(li->data, game_manager)->stupidity += random() % 5;
	for (gc_list *ent = scene->entities; ent; ent = ent->next)
		if (((gc_entity *)ent->data)->prefab_id == prefab_id)
			((gc_entity *)ent->data)->destroy(ent->data, scene);
	teams_move_up(scene, 15, y_pos);
	return (true);
}