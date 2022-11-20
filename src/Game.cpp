#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glm/glm.hpp>
        Game::Game()
        {
            isRunning = false;
            std::cout << "Game constructor called" << std::endl;
        }

        Game::~Game()
        {
            std::cout << "Game destructor called" << std::endl;
        }

        void Game::Initialize()
        {
            if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
                std::cerr << "Error initializing SDL." << std::endl;
                return;
            }
            SDL_DisplayMode displayMode;
            SDL_GetCurrentDisplayMode(0, &displayMode);
            windowWidth = 800;//displayMode.w;
            windowHeight = 600;//displayMode.h;
            window = SDL_CreateWindow(
                "Levi's Game Engine",
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                windowWidth,
                windowHeight,
                SDL_WINDOW_BORDERLESS
            );
            if (!window) {
                std::cerr << "Error creating SDL window." << std::endl;
            }
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (!renderer) {
                std::cerr << "Error creating SDL renderer." << std::endl;
            }
            SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

            isRunning = true;
        }

        void Game::Run()
        {
            Setup();

            while (isRunning) {
                ProcessInput();
                Update();
                Render();
            }
        }

        void Game::ProcessInput()
        {
            SDL_Event sdlEvent;
            while (SDL_PollEvent(&sdlEvent)) {
                switch (sdlEvent.type) {
                    case SDL_QUIT:
                        isRunning = false;
                        break;
                    case SDL_KEYDOWN:
                        if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
                            isRunning = false;
                        }
                        break;

                }
            }
        }

        glm::vec2 playerPostion;
        glm::vec2 playerVelocity;

        void Game::Setup() {
            playerPostion = glm::vec2(10.0, 20.0);
            playerVelocity = glm::vec2(50.0, 0.0);
        }

        void Game::Update()
        {
            // If we are too fast, we need to slow down until we reach MILLISECS_PER_FRAME
            int timeToWait = MILLISECS_PER_FRAME - (SDL_GetTicks() - millisecsPreviousFrame);
            if (timeToWait > 0 && timeToWait <= MILLISECS_PER_FRAME)
            {
                SDL_Delay(timeToWait);
            }

            double deltaTime = (SDL_GetTicks() - millisecsPreviousFrame) / 1000.0;

            // Store the current frame time
            millisecsPreviousFrame = SDL_GetTicks();

            playerPostion.x += playerVelocity.x * deltaTime;
            playerPostion.y += playerVelocity.y * deltaTime;

            if (playerPostion.x > 1366)
            {
                playerPostion.x = 0;
            }
        }

        void Game::Render()
        {
            SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
            SDL_RenderClear(renderer);

            // Draw a PNG texture
            SDL_Surface* surface = IMG_Load("./assets/images/tank-tiger-right.png");
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);

            SDL_Rect destRect = {
                static_cast<int>(playerPostion.x),
                static_cast<int>(playerPostion.y),
                32,
                32
            }; // The destination rectangle where we will place the texture
            SDL_RenderCopy(renderer, texture, NULL, &destRect);
            SDL_DestroyTexture(texture);

            SDL_RenderPresent(renderer); // Double buffer rendering
        }

        void Game::Destroy()
        {
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
        }
