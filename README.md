# Graphics w/ glew,glm & SDL
Essentially me trying to learn how to use OpenGL using glew,glm and SDL.
This includes all copying and linking of header files and libraries premade.


the Display class, for example, is thus:
```c++
#include<SDL2/SDL.h>
#undef main
class Display
{
public:
	Display(int width,int height,const std::string& title);
	void update();
	bool m_isoff;
	bool isoff();
	void Clear(float red, float blue, float green, float alpha);
	virtual ~Display();
protected:
private:
	SDL_Window* m_window;
	SDL_GLContext m_GLcontext;
};
```
more details will be provided in the future.
:bowtie:
