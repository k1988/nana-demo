
// Please, put a test audio file in "../Examples/audio1.wav"  in WAV PCM format
//
// you can donwload (an rename) an example from: 
// http://download.wavetlan.com/SVV/Media/HTTP/WAV/NeroSoundTrax/NeroSoundTrax_test3_PCM_Mono_CBR_8SS_8000Hz.wav


#include <nana/gui/wvl.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/audio/player.hpp>
#include <nana/threads/pool.hpp>

int main()
{
    nana::audio::player player(STR("../Examples/audio1.wav"));
    nana::threads::pool pool(1); //Only 1 thread.

    using namespace nana;

    form fm;
    button btn     (fm, nana::rectangle(10, 10, 180, 24));
    button btn_wait(fm, nana::rectangle(10, 40, 180, 24));
    btn     .caption(STR("Play the audio"));
    btn_wait.caption(STR("Play and wait 5 min !!!!"));

    //C++11
    btn.events().click(pool_push(pool, [&]()
                           {
                               player.play();
                           }));
    btn_wait.events().click([&]()
                       {
                         player.play();
                       });

    fm.show();

    exec();
}
