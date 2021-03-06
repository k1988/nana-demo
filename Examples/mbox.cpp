#include <nana/gui/wvl.hpp>

void when_exit(const nana::arg_unload& ei)
{
    nana::msgbox m(ei.window_handle, STR("msgbox example"), nana::msgbox::yes_no);
    m.icon(m.icon_question);
    m<<STR("Are you sure you want to exit the game?");
    ei.cancel = (m() != m.pick_yes);
}
int main()
{
    using namespace nana;
    form fm;
    fm.events().unload(when_exit);
    fm.show();
    exec();
}