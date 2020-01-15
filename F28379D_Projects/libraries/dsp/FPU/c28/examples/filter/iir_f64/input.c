//#############################################################################
//! \file   input.c
//! \brief  Input Vector (512) 
//! \author Vishal Coelho 
//! \date   23-Feb-2016
//! 
//
//  Group:          C2000
//  Target Family:  $DEVICE$
//
//#############################################################################
// $TI Release: C28x Floating Point Unit Library V2.01.00.00 $
// $Release Date: May 27, 2019 $
// $Copyright: Copyright (C) 2019 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//#############################################################################


#include "dsp.h"

const float64_t test_input[533] = {
     8.506175670838L, 11.478202551275L,  7.262634956366L,  2.067279320260L, 
     1.643755060659L,  3.197307665970L,  1.498297487314L, -2.800755352218L, 
    -5.467778824683L, -5.149267582677L, -3.770458657576L, -3.430550569904L, 
    -5.105138594285L, -7.655210256168L, -7.494464720085L, -2.854021883573L, 
     1.986465726369L,  1.682064869212L, -1.552647446242L, -0.704561794106L, 
     4.662182733463L,  7.398064363860L,  4.510645950188L,  1.938025007615L, 
     4.501923648327L,  8.285107030532L,  7.317409083212L,  2.254971429925L, 
    -1.970886242832L, -3.035716073850L, -2.174624070013L, -1.443914871747L, 
    -2.402735126479L, -4.740039773263L, -5.432270679886L, -2.672195815317L, 
    -0.129623558814L, -2.334530910237L, -6.526825356245L, -5.710216949903L, 
     0.037547905371L,  2.937860270705L, -0.286606507320L, -3.390794300940L, 
    -0.786802891253L,  4.379244411920L,  6.394210856744L,  5.381822157884L, 
     5.099491334390L,  6.570124062021L,  7.742191822450L,  6.611794092811L, 
     2.491373368083L, -3.066554017348L, -6.025808204523L, -4.220842304665L, 
    -1.657235578799L, -3.562647508684L, -7.755414551766L, -7.362942868322L, 
    -2.132721780990L,  0.627577198335L, -2.155088096199L, -4.523028306983L, 
    -1.547202261220L,  3.007044625667L,  3.305115560565L,  0.061647064216L, 
    -1.853337824055L, -0.308089063797L,  3.162382557843L,  6.149690509376L, 
     6.762957833906L,  5.073699143470L,  4.011096952572L,  5.453784692474L, 
     5.952282589861L,  1.296023185266L, -5.406399707319L, -6.853449146673L, 
    -2.917587916542L, -1.299711753376L, -5.320058091007L, -8.859474965333L, 
    -6.482644021803L, -1.456669743388L,  0.459314553426L, -0.565825052411L, 
    -0.653937028605L,  1.371614411034L,  3.588766035522L,  4.043692888175L, 
     1.983030123537L, -1.228636568884L, -1.837725587658L,  1.999368765085L, 
     5.985307729239L,  4.696652643473L,  0.259949768656L, -0.355238744023L, 
     3.327291770415L,  4.294327147737L, -0.234133006352L, -4.078303862381L, 
    -2.206512534356L,  1.584507176150L,  1.318141729566L, -2.488460663986L, 
    -5.146191011958L, -4.618466217587L, -2.402903152791L, -0.727513994618L, 
    -1.190549391883L, -3.381498384594L, -4.071409245688L, -1.205305466982L, 
     1.758956441750L,  0.395775983109L, -2.583347948262L, -0.388930169163L, 
     6.574840244237L, 10.157931940482L,  6.759899054502L,  2.439923445637L, 
     2.799127448145L,  4.921754631690L,  3.510067001415L, -0.788230565067L, 
    -3.687210721607L, -3.738883602585L, -2.760153622964L, -2.756870564224L, 
    -4.650047953282L, -7.297764242118L, -7.161336765058L, -2.555078055968L, 
     2.147729322997L,  1.527237131177L, -2.232285675735L, -2.087468695938L, 
     2.489940523070L,  4.490931240555L,  1.084588396391L, -1.643031203698L, 
     1.229714511069L,  5.810898189360L,  6.068660528150L,  2.515556225785L, 
    -0.120427838464L,  0.257090156178L,  2.201061327106L,  3.497711336071L, 
     2.512879167718L, -0.422995218675L, -2.178859118614L, -0.774807206779L, 
     0.322811616396L, -3.220139119929L, -8.489655027708L, -8.400713454201L, 
    -3.015391245276L, -0.161450420889L, -3.208698376626L, -6.018889418959L, 
    -3.096018629092L,  2.359279934226L,  4.627241874740L,  3.869219590941L, 
     3.908083842215L,  5.835276247571L,  7.644304738367L,  7.331380124019L, 
     4.153630525751L, -0.443567658747L, -2.565505960604L, -0.194634337473L, 
     2.540906256897L,  0.345122456767L, -4.595596596168L, -5.326676709288L, 
    -1.448258065416L, -0.081097697496L, -4.106154910341L, -7.404171556025L, 
    -4.944365272014L, -0.466837491538L,  0.142012374120L, -2.516567131061L, 
    -3.719723308193L, -1.482906293576L,  2.543685324501L,  5.891637646657L, 
     6.674386197624L,  5.025493112215L,  3.973380319273L,  5.503701509975L, 
     6.250617342401L,  2.038429352056L, -4.051615283093L, -4.805635672861L, 
    -0.226975367567L,  1.837901223052L, -2.057954134099L, -5.872382560778L, 
    -4.176355330540L, -0.166482227708L,  0.534850241330L, -1.725611316790L, 
    -2.885079629833L, -1.611728220237L,  0.267985009068L,  0.818727591564L, 
    -0.772649085383L, -3.264308419350L, -3.060144098057L,  1.526023321308L, 
     6.073002568558L,  5.091930303132L,  0.713156088827L, -0.026126617667L, 
     3.461696358262L,  4.288762842576L, -0.218211574497L, -3.819084600682L, 
    -1.484636988897L,  2.921720282731L,  3.306381610095L,  0.045168113824L, 
    -2.306434894037L, -1.807045323657L,  0.011302433887L,  0.955880326704L, 
    -0.473071993210L, -3.723679043269L, -5.412179486562L, -3.347081779755L, 
    -0.894821954117L, -2.450506179694L, -5.334519069681L, -2.838697154837L, 
     4.525964074117L,  8.506146339992L,  5.428551239781L,  1.328139487311L, 
     1.835380572469L,  4.107749036069L,  2.942491776601L, -0.925279196009L, 
    -3.159222372126L, -2.320078346794L, -0.301660776634L,  0.752135520695L, 
    -0.256452782576L, -2.367405284105L, -2.191367441745L,  1.874365445427L, 
     5.462198552437L,  3.252331799330L, -2.389204082902L, -4.184350535133L, 
    -1.356526241364L, -0.694684975950L, -4.874103546973L, -7.740790682361L, 
    -4.399018694299L,  1.151091919427L,  2.713311170996L,  0.614113810367L, 
    -0.591180218503L,  1.062824961045L,  4.055561633103L,  6.157979825600L, 
     5.765712161398L,  3.261241062575L,  1.823900395290L,  3.455948904899L, 
     4.675056280935L,  1.093502983807L, -4.451982725902L, -4.953591121597L, 
    -0.522855511785L,  1.015294757651L, -3.639050672186L, -8.210175940088L, 
    -7.012094997816L, -3.031298822292L, -1.785452490871L, -2.959807219481L, 
    -2.656173761816L,  0.198379396970L,  3.486407328271L,  5.019130671594L, 
     3.826340571320L,  1.122176123532L,  0.603535215119L,  4.152314062259L, 
     7.581571786611L,  5.611809673321L,  0.504812321609L, -0.677109238841L, 
     2.576038396070L,  3.229984060860L, -1.549453604951L, -5.638550695397L, 
    -4.033450744412L, -0.511448780144L, -0.980977564602L, -4.824983961261L, 
    -7.253550241347L, -6.164001010457L, -3.052299077683L, -0.223747247132L, 
     0.573133247351L, -0.448300942951L, -0.262814275272L,  3.018939011322L, 
     5.849301327798L,  3.809999269898L, -0.283485577516L,  0.536981267545L, 
     6.082697250488L,  8.411774579667L,  4.084753112146L, -0.751701129056L, 
    -0.490164980638L,  1.889820672303L,  0.981839999247L, -2.688607844346L, 
    -4.942562733348L, -4.404731192352L, -2.924758027252L, -2.508272369769L, 
    -4.058380014064L, -6.414623759987L, -6.031622395692L, -1.232515331977L, 
     3.590823790958L,  3.002427175110L, -0.813917016333L, -0.791729949082L, 
     3.642146293549L,  5.532741132044L,  2.091777147922L, -0.585370027114L, 
     2.383785995299L,  7.018488637727L,  7.164829681422L,  3.212678531637L, 
    -0.191604211091L, -0.952516500203L, -0.411985476537L, -0.572058070648L, 
    -2.777354421027L, -6.385481662556L, -8.002556026003L, -5.506422571437L, 
    -2.394929361041L, -3.226715207239L, -5.481925851355L, -2.574466521789L, 
     4.924829510305L,  8.774938799436L,  5.380328440824L,  0.897786492043L, 
     1.092643809718L,  3.236880506082L,  2.193865922743L, -1.299783897658L, 
    -2.971611889010L, -1.496847547750L,  1.092438283584L,  2.522935941404L, 
     1.607090239767L, -0.723476873601L, -1.038759954432L,  2.365334097446L, 
     5.260883430524L,  2.474543971543L, -3.507769577671L, -5.342243159543L, 
    -2.256068754947L, -1.111141083218L, -4.708699766140L, -7.045379949796L, 
    -3.366533958333L,  2.228538756177L,  3.509524623318L,  0.842697301038L, 
    -1.110564307703L, -0.234887778158L,  2.110980481272L,  3.837003674748L, 
     3.425472245570L,  1.275211756394L,  0.509036145722L,  3.013005864161L, 
     5.154614519860L,  2.394217882236L, -2.553732185716L, -2.750524022911L, 
     1.686955132336L,  2.987759090690L, -2.052573365180L, -7.048110362677L, 
    -6.216762492904L, -2.487010957030L, -1.369853091726L, -2.594523892111L, 
    -2.343026570525L,  0.365815447365L,  3.340000854572L,  4.359066822629L, 
     2.479968219780L, -0.995314315966L, -2.234857131032L,  0.799057370301L, 
     4.062373360579L,  2.371922503607L, -1.986552054434L, -2.011002697478L, 
     2.669409342282L,  4.824361303834L,  1.401187017276L, -1.677363164125L, 
     0.446262090351L,  3.929764031031L,  2.891610033914L, -1.939840536161L, 
    -5.602746178887L, -5.796700836636L, -3.832420371139L, -1.876081939376L, 
    -1.605262319749L, -2.810117849719L, -2.533272473153L,  1.005850281722L, 
     4.140715066610L,  2.354779526870L, -1.590706414722L, -0.726970868081L, 
     4.808810820132L,  7.159726353845L,  2.978387573878L, -1.517979110275L, 
    -0.696593574247L,  2.430375212433L,  2.367425228448L, -0.489659242155L, 
    -2.105553918892L, -1.230994128907L,  0.205011069076L,  0.183889655404L, 
    -2.138304901284L, -5.479844037571L, -6.135642727364L, -2.262944355649L, 
     1.884785714196L,  0.954873705978L, -2.856131877924L, -2.539334592074L, 
     2.366168031010L,  4.765981928027L,  1.738251333031L, -0.718426872913L, 
     2.240274383743L,  6.661779499775L,  6.478609341097L,  2.203336530263L, 
    -1.389420944093L, -2.102651749950L, -1.229859100268L, -0.791928091288L, 
    -2.218180678759L, -4.999976339552L, -5.897718231662L, -2.930279257372L, 
     0.308119239445L, -0.771056648171L, -3.604145900900L, -1.496646725811L, 
     5.130171113166L,  8.193469305935L,  4.230227454058L, -0.524232698925L, 
    -0.295943443164L,  2.125878764499L,  1.489581689989L, -1.608775727441L, 
    -3.028722612080L, -1.536779723311L,  0.807162110180L,  1.773613863656L, 
     0.282084756942L, -2.588671435803L, -3.254276228835L,  0.115815202663L, 
     3.362559524977L,  1.306390847928L, -3.649600547067L, -4.306180281641L, 
    -0.068977919081L,  2.022609735552L, -0.975133345969L, -3.140227261035L, 
     0.274323267453L,  5.232224096354L,  5.619316961619L,  1.943739517810L, 
    -0.996308685875L, -0.980563656341L,  0.688222624972L,  1.923585852716L, 
     1.000000000000L, -1.589116348424L,  1.000000000000L,  1.000000000000L, 
     1.807689688220L, -0.917293592267L,  1.000000000000L, -1.129384861204L, 
     1.000000000000L,  1.000000000000L,  1.703138978970L, -0.764114321317L, 
     1.000000000000L,  1.000000000000L,  0.000000000000L,  1.000000000000L, 
     0.829537745791L,  0.000000000000L,  0.156921156840L,  0.070037080256L, 
     0.144885155960L, }; 


// End of File
