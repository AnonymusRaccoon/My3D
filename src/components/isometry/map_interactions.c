/*
** EPITECH PROJECT, 2020
** Gamacon
** File description:
** map_interactions
*/

#include "map_interactions.h"
#include "clickable_component.h"
#include "entity.h"
#include "my.h"
#include <math.h>
#include "components/transform_component.h"
#include "map_managment.h"
#include <stdlib.h>
#include <components/isometry/map_manager_component.h>

void click_tile(gc_engine *engine, struct map_manager_component *manager, \
struct tile *ret, bool is_left)
{
	bool r = manager->brush == RESET;

	switch (manager->brush) {
	case ROTATE:
		ret->data = (ret->data + (is_left ? 1 : -1U)) % 4;
		break;
	case TEXTURE:
		ret->texture = manager->selected_texture;
		break;
	case MOVE:
	case RESET:
		move_tile(engine, ret, ALL_VERTICES | is_left, r);
		break;
	}
}

void do_the_tile_interact(gc_engine *engine, void **dodge, \
enum gc_mousekeys key, gc_vector2 pos)
{
	int ind;
	struct map_manager_component *manager = dodge[1];
	struct vertex_component *map = dodge[0];
	struct tile *ret = get_tile_from_pos(map, pos);
	bool r = manager->brush == RESET;

	if (!ret)
		return;
	if (manager->tile_mode)
		click_tile(engine, manager, ret, key == GC_LEFT);
	else {
		ind = get_index_nearest_vertex(ret, pos);
        move_tile(engine, ret, ((int) pow(2, ind + 1)) | (key == GC_LEFT), r);
	}
}

bool tile_interact(gc_engine *engine, gc_entity *entity, gc_vector2 pos, \
enum gc_mousekeys key)
{
	struct map_manager_component *m = GETCMP(entity, map_manager_component);
	struct transform_component *tc = GETCMP(entity, transform_component);
	struct vertex_component *map = GETCMP(entity, vertex_component);
	void *dodge[2] = {map, m};

	if (!map || !m || !tc) {
		my_printf("map not found\n");
		return (false);
	}
	pos.x -= tc->position.x;
	pos.y += tc->position.y;
	do_the_tile_interact(engine, dodge, key, pos);
	return (false);
}

void move_tile(gc_engine *engine, struct tile *ret, char mode, bool r)
{
	int val = (mode & INVERT_ADD_VALUE) ? ADD_VALUE : -ADD_VALUE;

	for (int i = 0; i < 4; i++) {
		if (mode & (int)pow(2, i + 1))
			ret->corners[i]->z += (r) ? -ret->corners[i]->z : val;
	}
}