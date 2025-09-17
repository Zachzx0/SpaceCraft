
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

void DrawRect(SDL_Renderer *renderer, const SDL_Rect *rect, const SDL_Color *color);

int main(int argc, char *args[])
{
    // using namespace std;

    // cout<<"Hello World";

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    }

    // SDL_Window* window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

    // 创建窗口
    SDL_Window *window = SDL_CreateWindow("Hello world", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    }

    // 创建渲染器
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    while (true)
    {
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                break;
            }

            SDL_RenderClear(renderer); // 清屏

            SDL_Color bgColor;

            SDL_GetRenderDrawColor(renderer, &bgColor.r, &bgColor.g, &bgColor.b, &bgColor.a); // 设置颜色

            SDL_Color rectColor{255, 0, 0, 255};
            SDL_Rect rect{100, 100, 200, 200};
            DrawRect(renderer, &rect, &rectColor);
            SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a); // 设置颜色

             SDL_Color rectColor2{0, 255, 0, 255};
            SDL_Rect rect2{400, 400, 100, 100};
            DrawRect(renderer, &rect2, &rectColor2);
            SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a); // 设置颜色

            SDL_RenderPresent(renderer); // 显示渲染器;
        }
    }

     // 清理并退出

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();

        // SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        // SDL_RenderClear(renderer);

        // SDL_RenderPresent(renderer);

        // SDL_Delay(2000);
        return 0;
}
void DrawRect(SDL_Renderer *renderer, const SDL_Rect *rect, const SDL_Color *color)
{
    SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a); // 设置颜色
    SDL_RenderFillRect(renderer, rect);              // 填充矩形
}