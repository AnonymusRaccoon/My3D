//
// Created by anonymus-raccoon on 3/2/20.
//

#include "engine.h"
#include "setup.h"
#include <stdbool.h>
#include <sprite.h>
#include "components/renderer.h"
#include "systems/sfml_renderer_system.h"

int checkbox_update(gc_scene *s, gc_entity *entity, bool checked)
{
	struct renderer *renderer;
	char *sprite = checked ? "check" : "cross";

	if (!entity)
		return (-1);
	renderer = GETCMP(entity, renderer);
	if (!renderer || renderer->type != GC_TEXTUREREND)
		return (-1);

	((gc_sprite *)renderer->data)->texture = s->get_data(s, "sprite", sprite);
	return (0);
}

bool fullscreen(gc_engine *engine, int entity_id)
{
	gc_entity *entity = engine->scene->get_entity(engine->scene, entity_id);
	struct sfml_renderer_system *renderer = GETSYS(engine, sfml_renderer_system);

	if (!renderer)
		return (false);
	renderer->is_fullscreen = !renderer->is_fullscreen;
	if (checkbox_update(engine->scene, entity, renderer->is_fullscreen) < 0)
		return (false);
	sfRenderWindow_destroy(renderer->window);
	if (renderer->is_fullscreen)
		renderer->window = sfRenderWindow_create(sfVideoMode_getDesktopMode(), \
"My3D", sfFullscreen | sfClose, NULL);
	else
		renderer->window = sfRenderWindow_create((sfVideoMode){800, 600, 32}, \
"My3D", sfDefaultStyle, NULL);
	return (true);
}