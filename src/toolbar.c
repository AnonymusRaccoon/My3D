//
// Created by anonymus-raccoon on 3/11/20.
//

#include <stdbool.h>
#include <components/isometry/map_manager_component.h>
#include "engine.h"
#include "entity.h"

bool tile_select(gc_engine *engine, gc_entity *entity, gc_vector2 _)
{
	gc_scene *scene = engine->scene;
	gc_list *list = scene->get_entity_by_cmp(scene, "map_manager_component");
	struct map_manager_component *manager;

	if (!list)
		return (false);
	manager = GETCMP(list->data, map_manager_component);
	manager->tile_mode = true;
	return (true);
}

bool vertex_select(gc_engine *engine, gc_entity *entity, gc_vector2 _)
{
	gc_scene *scene = engine->scene;
	gc_list *list = scene->get_entity_by_cmp(scene, "map_manager_component");
	struct map_manager_component *manager;

	if (!list)
		return (false);
	manager = GETCMP(list->data, map_manager_component);
	manager->tile_mode = false;
	return (true);
}

bool up_down(gc_engine *engine, gc_entity *entity, gc_vector2 _)
{
	gc_scene *scene = engine->scene;
	gc_list *list = scene->get_entity_by_cmp(scene, "map_manager_component");
	struct map_manager_component *manager;

	if (!list)
		return (false);
	manager = GETCMP(list->data, map_manager_component);
	manager->brush = MOVE;
	return (true);
}

bool rotate(gc_engine *engine, gc_entity *entity, gc_vector2 _)
{
	gc_scene *scene = engine->scene;
	gc_list *list = scene->get_entity_by_cmp(scene, "map_manager_component");
	struct map_manager_component *manager;

	if (!list)
		return (false);
	manager = GETCMP(list->data, map_manager_component);
	manager->brush = ROTATE;
	return (true);
}