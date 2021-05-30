//
// Created by grzegorz on 5/26/21.
//

#ifndef VPET_MENU_H
#define VPET_MENU_H

#include <vector>
#include "../../display/drawable/text/Text.h"
#include "../../display/drawable/sprite/Sprite.h"
#include "../../../runtime/stage/Stage.h"
#include "../../../assets/menu-cursor.texture.h"

namespace tama
{
    class Menu
    {
    public:
        Menu(std::shared_ptr<Scene> scene, const std::shared_ptr<Context> &context, std::vector<std::string> options);

        Menu(std::shared_ptr<Scene> scene, const std::shared_ptr<Context> &context);

        void setOptions(std::vector<std::string> options);
        int getSelectedItem();
        void moveToNextItem();

    private:

        std::shared_ptr<Scene> scene;
        std::shared_ptr<Context> context;
        int selectedItem = 0;
        Sprite cursor;
        std::vector<Text> optionTexts;
        std::vector<std::shared_ptr<Stage>> optionOnClickStages;

//        void addOption(std::string optionName, std::shared_ptr<Stage> onClickStage);


        void initMenu();

        std::vector<std::string> options;

    };
}



#endif //VPET_MENU_H
