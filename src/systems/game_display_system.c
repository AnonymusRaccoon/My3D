/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** teams_system
*/

#include "entity.h"
#include "system.h"
#include <stddef.h>
#include "components/game_display.h"
#include "components/game_manager.h"
#include "text.h"
#include "components/renderer.h"
#include <malloc.h>

static void update_entity(gc_engine *engine, void *system, gc_entity *entity, \
float dtime)
{
	struct game_display *disp = GETCMP(entity, game_display);
	struct renderer *rend = GETCMP(entity, renderer);
	struct game_manager *manager;
	gc_scene *scene = engine->scene;
	gc_list *entities = scene->get_entity_by_cmp(scene, "game_manager");

	if (!entities)
		return;
	manager = GETCMP(entities->data, game_manager);
	if (rend->type != GC_TXTREND)
		return;
	if (disp->type == HAPPINESS_DISPLAY)
		sprintf(((gc_text *)rend->data)->text, "%d%%", manager->happiness);
	else
		sprintf(((gc_text *)rend->data)->text, "%d%%", manager->stupidity);
}

static void destroy(void *system)
{
	(void)system;
}

const gc_system game_display_system = {
	name: "game_display_system",
	component_name: "game_display",
	size: sizeof(gc_system),
	ctr: NULL,
	dtr: NULL,
	check_dependencies: &system_check_dependencies,
	update_entity: &update_entity,
	destroy: &destroy
};