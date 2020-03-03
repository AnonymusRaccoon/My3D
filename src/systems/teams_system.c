/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** teams_system
*/

#include "entity.h"
#include "system.h"
#include "sprite.h"
#include "vector2.h"
#include "prefab.h"
#include "components/teams_component.h"
#include "systems/teams_system.h"
#include <stddef.h>
#include <dirent.h>
#include <stdlib.h>

static void update_entity(gc_engine *engine, void *system, gc_entity *entity, \
float dtime)
{
	struct teams_component *team = GETCMP(entity, teams_component);

	team->next_teams -= dtime;
	if (team->next_teams < 0 && team->prefab_count) {
		team->next_teams = team->delay;
		prefab_load(engine, team->prefabs[random() % team->prefab_count]);
	}
}

static void destroy(void *system)
{
	(void)system;
}

const gc_system teams_system = {
	name: "teams_system",
	component_name: "teams_component",
	size: sizeof(gc_system),
	ctr: NULL,
	dtr: NULL,
	check_dependencies: &system_check_dependencies,
	update_entity: &update_entity,
	destroy: &destroy
};