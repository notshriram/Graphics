#pragma once
#include<string>
#include<SDL2/SDL.h>
#undef main
class Display
{
public:
	Display(int width,int height,const std::string& title);
	void update();
	bool m_isoff;
	bool isoff();
	void Clear(float r, float g, float b, float a);
	virtual ~Display();
protected:
private:
	Display(const Display& other){}
	Display& operator=(const Display& other){}
	SDL_Window* m_window;
	SDL_GLContext m_GLcontext;
};

