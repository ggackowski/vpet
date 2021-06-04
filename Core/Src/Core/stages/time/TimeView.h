//
// Created by grzegorz on 6/4/21.
//

#ifndef VPET_TIMEVIEW_H
#define VPET_TIMEVIEW_H

#include "../../runtime/stage/Stage.h"
#include "../../ui/display/drawable/text/Text.h"
#include "../../common/util/displayPlacementUtils.h"

namespace tama
{
    class TimeView : public Stage
    {
    public:
        TimeView(const std::shared_ptr<Context> &context);

        void onInput(Button button) override;

        void onInit() override;

        void onFrame() override;
    private:
        Text timeText = Text(context->getGameState().getDateTime().toString(), tama::util::toContentArea(Vec2d(0, 0)));

    };

}


#endif //VPET_TIMEVIEW_H
