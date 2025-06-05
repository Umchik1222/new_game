#include <stdio.h>
#include <stdbool.h>
#include <glad/glad.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

/*
 OpenGL (Open Graphics Library) - это межплатформенный
 программный интерфейс (API) для работы с 2D и 3D графикой.
 Он предоставляет набор функций и процедур для создания и
 управления графическими объектами, такими как полигоны,
 текстуры и шейдеры.
*/

/*
 SDL (Simple DirectMedia Layer) - это мультимедийная библиотека,
 предоставляющая низкоуровневый доступ к видеокарте, звуку,
 клавиатуре, мыши и другим устройствам ввода-вывода. Она
 упрощает создание игр и мультимедийных приложений.
*/


int main(int args, char *argv[]){

    //Установка атрибутов контекста OpenGL в SDL
    /*
     Атрибуты контекста определяют версию и профиль OpenGL,
     который будет использоваться при создании контекста.
     Профиль представляет собой спецификацию, которая определяет
     набор доступных функций и возможностей.

     SDL_GL_CONTEXT_PROFILE_MASK - определяет профиль OpenGL
     SDL_GL_CONTEXT_PROFILE_CORE - Core Profile(основные возможности, не включает устаревшие возможности)
     Устанавливаем версию 3.3
     Минорная версия часто включает в себя багфикс основной, расширения и оптимизацию
    */
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,3);

    // Инициализация библиотеки OpenGL с использованием SDL
    /*
     В данном коде первым делом происходит инициализация библиотеки SDL
     с поддержкой видео.
    */
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Could not init SDL: %s\n", SDL_GetError());
        exit(1);
    }

    //Создание окна
    SDL_Window *window = SDL_CreateWindow(
        "MyGame",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_OPENGL
    );

    if (!window) {
        printf("Failed to init window: %s\n", SDL_GetError);
        exit(1);
    }

    //Создание контекста OpenGL и загрузка функций OpenGL с помощью GLAD
    /*
     Контекст OpenGL - это объект, который содержит все состояния OpenGL,
     такие как текущий буфер кадров, текстуры и шейдеры,
     а также все функции OpenGL, которые могут быть вызваны.

     Вторая строка загружает все необходимые
     функции OpenGL с помощью GLAD используя указатель на функцию SDL_GL_GetProcAddress.

     GLAD - это кросс-платформенная библиотека, предназначенная
     для загрузки всех необходимых функций OpenGL для работы с конкретной
     версией OpenGL, которую вы используете.


    */
    SDL_GL_CreateContext(window);// Когда контекст создан, мы можем использовать функции OpenGL в для рисования этом окне
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        printf("Faild to load GL: %s\n", SDL_GetError());
        exit(1);
    }

    //Вывод информации о загруженной версии OpenGL
    puts("OpenGL Loaded");
    printf("Vendor: %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version: %s\n", glGetString(GL_VERSION));

    puts("Hello word!");

    //Цикл обработки SDL событий, включая проверку на закрытие окна
    bool should_quit = false;

    while (!should_quit) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    should_quit = true;
                    break;
                default:
                    break;
            }
        }

    }
    return 0;
}