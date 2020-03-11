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

bool tile_interact(gc_engine *engine, gc_entity *entity, gc_vector2 pos, \
enum gc_mousekeys key)
{
	struct vertex_component *map = GETCMP(entity, vertex_component);
	struct map_manager_component *manager = GETCMP(entity, map_manager_component);
	struct tile *ret = get_tile_from_pos(map, pos);
	bool r = manager->brush == RESET;
	int ind;

	if (!map || !manager) {
		my_printf("map not found\n");
		return (false);
	}
	if (!ret)
		return (false);
	if (manager->tile_mode)
		click_tile(engine, manager, ret, key == GC_LEFT);
	else {
		ind = get_index_nearest_vertex(ret, pos);
		move_tile(engine, ret, ((int) pow(2, ind + 1)) | (key == GC_LEFT), r);
	}
	return (false);
}

void move_tile(gc_engine *engine, struct tile *ret, char mode, bool r)
{
	int val = (mode & INVERT_ADD_VALUE) ? ADD_VALUE : -ADD_VALUE;

	if (mode & VERTEX_0)
		ret->corners[0]->z += (r) ? -ret->corners[0]->z : val;
	if (mode & VERTEX_1)
		ret->corners[1]->z += (r) ? -ret->corners[1]->z : val;
	if (mode & VERTEX_2)
		ret->corners[2]->z += (r) ? -ret->corners[2]->z : val;
	if (mode & VERTEX_3)
		ret->corners[3]->z += (r) ? -ret->corners[3]->z : val;
}