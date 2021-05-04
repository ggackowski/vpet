//
// Created by grzegorz on 4/29/21.
//

#ifndef VPET_CONTEXT_H
#define VPET_CONTEXT_H


#include <stack>
#include <memory>
#include "../stage/Stage.h"
#include "../../ui/display/drawable/texture-loader/TextureLoader.h"
#include "../../input/Input.h"

namespace tama
{
    class Stage;

    class Context
    {
    public:
        Context(std::shared_ptr<TextureLoader> textureLoader, std::shared_ptr<Input> input);

        void openNewStage(std::shared_ptr<tama::Stage>);
        void goToPreviousStage();
        void switchStage(std::shared_ptr<tama::Stage>);
        std::shared_ptr<tama::Stage> getActiveStage();
        std::shared_ptr<TextureLoader> getTextureLoader();
        std::shared_ptr<Input> getInput();
    private:
        std::stack<std::shared_ptr<Stage>> stages;
        std::shared_ptr<TextureLoader> textureLoader;
        std::shared_ptr<Input> input;
    };
}



#endif //VPET_CONTEXT_H
