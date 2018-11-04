#pragma once

#include "../Game.h"
#include "ECS.h"
#include "Components.h"


class KeyboardController : public Component
{
public:
	TransformComponent *transform;
	SpriteComponent *sprite;

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		sprite = &entity->getComponent<SpriteComponent>();
	}

	void update() override
	{
		if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.y = -1;
				transform->velocity.x = 0;
				sprite->Play("Walk Up");
				break;
			case SDLK_a:
				transform->velocity.x = -1;
				transform->velocity.y = 0;
				sprite->Play("Walk Left");
				sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
				break;
			case SDLK_d:
				transform->velocity.x = 1;
				transform->velocity.y = 0;
				sprite->Play("Walk Left");
				sprite->spriteFlip = SDL_FLIP_NONE;
				break;
			case SDLK_s:
				transform->velocity.y = 1;
				transform->velocity.x = 0;
				sprite->Play("Walk Down");
				break;
			default:
				break;
			}
		}

		if (Game::event.type == SDL_KEYUP)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.y = 0;
				if(transform->velocity.x == 0) sprite->Play("Idle Back");
				break;
			case SDLK_a:
				transform->velocity.x = 0;
				if (transform->velocity.y == 0) {
					sprite->Play("Idle Side");
					sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
				}
				break;
			case SDLK_d:
				transform->velocity.x = 0;
				if (transform->velocity.y == 0) sprite->Play("Idle Side");
				break;
			case SDLK_s:
				transform->velocity.y = 0;
				if (transform->velocity.x == 0) sprite->Play("Idle Front");
				break;
			case SDLK_F4:
				Game::isRunning = false;
			default:
				break;
			}

		}
	}

};
