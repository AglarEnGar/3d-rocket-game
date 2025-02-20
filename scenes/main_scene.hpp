#pragma once
#include <core/scene/scene.hpp>
#include <core/event/input_poll.hpp>
#include <core/system_framework/system_registry.hpp>
#include <scene/components/components.hpp>
#include <core/update_handlers/sync_update.hpp>
#include <renderer/renderer.hpp>
#include "content/CharacterController.hpp"



namespace engine3d{
    // struct particle{
    //     engine3d::Ref<engine3d::SceneObject> RenderTarget=nullptr;
    //     bool IsAlive = true;
    //     glm::vec3 Velocity;
    //     glm::vec3 VelocityVariation;
    
    //     float LifeTime=1.f;
    //     float LifeRemaining=0.f;
    
    
    //     operator engine3d::Ref<engine3d::SceneObject>(){ return RenderTarget; }
    
    //     operator engine3d::Ref<engine3d::SceneObject>() const { return RenderTarget; }
    // };

    class MainScene : public SceneScope{
    public:
        MainScene();
        MainScene(const std::string& Tag);

        virtual ~MainScene(){}

    private:
        void EmitParticles();
        void OnUpdate();
        void OnUIUpdate();
        void OnPhysicsUpdate();
        void OnSceneRender();
        bool on_click_check = false;
        glm::vec2 last_cursor_pos;
        bool editor = false;
        void getViewPortControl
        (
            PerspectiveCamera& perspective_camera, 
            float deltaTime, bool click_check
        );
    private:
        // bool m_IsMeshFilepathSelected=false;
        std::string m_MeshFilepath="";
        Ref<SceneObject> m_MainCamera=nullptr;
        Ref<SceneObject> m_Sphere=nullptr;
        Ref<SceneObject> m_Rocket=nullptr;
        Ref<SceneObject> m_moon=nullptr;

        Ref<SceneObject> m_box[4];
        CharacterController* cc = nullptr;
        bool m_game_mode = false;
        float previous_z_axis=0.f;
    };
};