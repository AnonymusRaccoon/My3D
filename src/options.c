//
// Created by anonymus-raccoon on 3/2/20.
//

#include "engine.h"
#include "setup.h"
#include <stdbool.h>
#include <sprite.h>
#include "components/renderer.h"
#include "components/input_component.h"
#include "systems/sfml_renderer_system.h"

bool fullscreen(gc_engine *engine, int entity_id)
{
	gc_scene *s = engine->scene;
	gc_entity *entity = s->get_entity(s, entity_id);
	struct sfml_renderer_system *rendsys = GETSYS(engine, sfml_renderer_system);
	struct renderer *renderer = GETCMP(entity, renderer);
	struct input_component *input = GETCMP(entity, input_component);
	char *sprite;
	char *title;

	if (!renderer || renderer->type != GC_TEXTUREREND || !input || !rendsys)
		return (false);
	input->value = !input->value;
	sprite = input->value == 0 ? "check" : "cross";
	((gc_sprite *)renderer->data)->texture = s->get_data(s, "sprite", sprite);
	sfRenderWindow_destroy(rendsys->window);
	if (input->value == 0)
		rendsys->window = sfRenderWindow_create(sfVideoMode_getDesktopMode(), \
"My3D", sfFullscreen | sfClose, NULL);
	else
		rendsys->window = sfRenderWindow_create((sfVideoMode){800, 600, 32}, \
"My3D", sfDefaultStyle, NULL);
	return (true);
}