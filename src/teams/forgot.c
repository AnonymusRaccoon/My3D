//
// Created by anonymus-raccoon on 3/6/20.
//

#include <stdbool.h>
#include "components/game_manager.h"
#include "components/teams_component.h"
#include "engine.h"

bool forgot_lmfao(gc_engine *engine, int id)
{
	gc_scene *scene = engine->scene;
	gc_list *li = scene->get_entity_by_cmp(scene, "game_manager");

	if (!li)
		return (false);
	GETCMP(li->data, game_manager)->happiness -= 5;
	GETCMP(li->data, game_manager)->stupidity -= 5;
	pm_clicked(engine, id);
	return (true);
}

bool forgot_ok(gc_engine *engine, int id)
{
	gc_scene *scene = engine->scene;
	gc_list *li = scene->get_entity_by_cmp(scene, "game_manager");

	if (!li)
		return (false);
	GETCMP(li->data, game_manager)->happiness += 2;
	GETCMP(li->data, game_manager)->stupidity += 6;
	pm_clicked(engine, id);
	return (true);
}