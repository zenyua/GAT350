#include "World01.h"
#include "Framework/Framework.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"

namespace nc
{
    bool World01::Initialize()
    {
        for (int i = 0; i < 10; i++) {
            m_positions.push_back({ randomf(-1, 1), randomf(-1, 1) });
        }
        return true;
    }

    void World01::Shutdown()
    {
    }

    void World01::Update(float dt)
    {
        m_scale += dt;
        m_position.x += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_A) ? -dt : 0;
        m_position.x += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_D) ? dt : 0;
        m_position.y += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_W) ? dt : 0;
        m_position.y += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_S) ? -dt : 0;
        m_angle += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_RIGHT) ? -dt * 90 : 0;
        m_angle += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_LEFT) ? dt * 90 : 0;
        m_time += dt;
    }

    void World01::Draw(Renderer& renderer)
    {
        // pre-render
        renderer.BeginFrame();
        glPushMatrix();
        glTranslatef(m_position.x, m_position.y, 0);
        glScalef(((sin(m_scale) + 2.0f) * 0.1f), ((sin(m_scale) + 2.0f) * 0.1f), 1);
        glRotatef(m_angle, 0, 0, 1);

        glBegin(GL_POLYGON);

        glColor3f(0.5f, 0.5f, 1.0f);
        glVertex2f(-0.5f, -1.0f);

        glColor3f(1.0f, 0.5f, 0.5f);
        glVertex2f(0.5f, -1.0f);

        glColor3f(0.5f, 1.0f, 0.5f);
        glVertex2f(1.0f, 0.0f);

        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex2f(0.0f, 1.0f);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-1.0f, 0.0f);

        glEnd();

        glPopMatrix();

        //for (int i = 0; i < 10; i++) {
        //    // render
        //    glPushMatrix();
        //    glTranslatef(m_positions[i].x, m_positions[i].y, 0);
        //    //glRotatef(m_angle, 1, 1, 1);
        //    glScalef((sin(m_time) + 1) * 0.5f, 1, 1);

        //    glBegin(GL_TRIANGLES);

        //    glColor3f(0.5f, 0.5f, 1.0f);
        //    glVertex2f(-0.5f, -0.5f);

        //    glColor3f(1.0f, 0.5f, 0.5f);
        //    glVertex2f(0.0f, 0.5f);

        //    glColor3f(0.5f, 1.0f, 0.5f);
        //    glVertex2f(0.5f, -0.5f);

        //    glEnd();

        //    glPopMatrix();
        //}
        
        // post-render
        renderer.EndFrame();
    }
}
