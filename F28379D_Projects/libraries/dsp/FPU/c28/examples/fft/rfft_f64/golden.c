//#############################################################################
//! \file golden.c
//! \brief  Ouput Vector (512) 
//! \author Vishal Coelho 
//! \date   20-Jan-2016
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

const float64_t test_golden[2048] = {
	 4.696141660431L,  0.000000000000L,  4.706272395223L, -0.796669570526L, 
	 4.736799226982L, -1.598572424669L,  4.788130535076L, -2.411058387725L, 
	 4.860962225119L, -3.239715861442L,  4.956301657020L, -4.090505293377L, 
	 5.075503288524L, -4.969910975683L,  5.220318447882L, -5.885119650108L, 
	 5.392962771060L, -6.844236820047L,  5.596206378717L, -7.856555282357L, 
	 5.833494049771L, -8.932895741241L,  6.109105819211L, -10.086047331666L, 
	 6.428373143706L, -11.331347879730L,  6.797972949134L, -12.687462100144L, 
	 7.226333028693L, -14.177444615131L,  7.724200038581L, -15.830220483004L, 
	 8.305450436159L, -17.682690964994L,  8.988273755662L, -19.782798815042L, 
	 9.796943086761L, -22.194107955330L, 10.764542272964L, -25.002851564611L, 
	11.937311558717L, -28.329156861214L, 13.381854060381L, -32.345653658112L, 
	15.197669836294L, -37.309834287126L, 17.540256933658L, -43.623689383942L, 
	20.666870311751L, -51.951829827420L, 25.035930285296L, -63.478093559561L, 
	31.551284497485L, -80.536062034456L, 42.276560394472L, -108.453019749154L, 
	63.173518218082L, -162.618461027846L, 121.541038928366L, -313.499309501207L, 
	1172.842521981999L, -3027.431264421202L, -158.893024828945L, 409.971000100375L, 
	-75.698370666560L, 195.023642655435L, -50.254768090003L, 129.154881193903L, 
	-37.935568209654L, 97.169777229013L, -30.675754912829L, 78.249862657850L, 
	-25.894554435549L, 65.733146563378L, -22.511154734627L, 56.829500195394L, 
	-19.993235640675L, 50.164629106519L, -18.048213864782L, 44.983083661334L, 
	-16.501946493186L, 40.835155766082L, -15.244311555273L, 37.436405299933L, 
	-14.202267777860L, 34.598118570985L, -13.325461907192L, 32.190155839951L, 
	-12.578056642227L, 30.119856148550L, -11.933853274950L, 28.319446817872L, 
	-11.373256922659L, 26.738209271026L, -10.881320347795L, 25.337429053072L, 
	-10.446444152598L, 24.087040187880L, -10.059490017521L, 22.963335758614L, 
	-9.713161560889L, 21.947369330027L, -9.401563108608L, 21.023815638562L, 
	-9.119879460529L, 20.180143637347L, -8.864139637922L, 19.406006345721L, 
	-8.631039995912L, 18.692783959708L, -8.417809999249L, 18.033237109660L, 
	-8.222109122167L, 17.421240477232L, -8.041946767143L, 16.851575848289L, 
	-7.875619422992L, 16.319769681535L, -7.721660883611L, 15.821964405258L, 
	-7.578802467458L, 15.354815542421L, -7.445940970521L, 14.915408810723L, 
	-7.322112654511L, 14.501192812841L, -7.206471985169L, 14.109923998848L, 
	-7.098274139068L, 13.739621366076L, -6.996860522426L, 13.388528943016L, 
	-6.901646714110L, 13.055084539285L, -6.812112372569L, 12.737893572904L, 
	-6.727792743591L, 12.435707037128L, -6.648271480566L, 12.147402861998L, 
	-6.573174546725L, 11.871970075128L, -6.502165013983L, 11.608495282770L, 
	-6.434938608415L, 11.356151083634L, -6.371219880392L, 11.114186100240L, 
	-6.310758899632L, 10.881916370002L, -6.253328393222L, 10.658717884192L, 
	-6.198721258962L, 10.444020099853L, -6.146748397903L, 10.237300279565L, 
	-6.097236819382L, 10.038078538189L, -6.050027979452L,  9.845913495502L, 
	-6.004976319919L,  9.660398449827L, -5.961947980339L,  9.481158001089L, 
	-5.920819659592L,  9.307845062794L, -5.881477607204L,  9.140138211517L, 
	-5.843816727518L,  8.977739330169L, -5.807739782298L,  8.820371507639L, 
	-5.773156679391L,  8.667777162778L, -5.739983836855L,  8.519716365177L, 
	-5.708143613376L,  8.375965329024L, -5.677563797089L,  8.236315059492L, 
	-5.648177145946L,  8.100570133907L, -5.619920973689L,  7.968547602234L, 
	-5.592736776257L,  7.840075993429L, -5.566569894094L,  7.714994415925L, 
	-5.541369206433L,  7.593151741954L, -5.517086854064L,  7.474405866721L, 
	-5.493677987580L,  7.358623034484L, -5.471100538394L,  7.245677224587L, 
	-5.449315010180L,  7.135449591277L, -5.428284288660L,  7.027827951877L, 
	-5.407973467878L,  6.922706318483L, -5.388349691326L,  6.819984468915L, 
	-5.369382006477L,  6.719567553122L, -5.351041231423L,  6.621365731645L, 
	-5.333299832461L,  6.525293843131L, -5.316131811607L,  6.431271098181L, 
	-5.299512603111L,  6.339220797142L, -5.283418978142L,  6.249070069648L, 
	-5.267828956919L,  6.160749633994L, -5.252721727607L,  6.074193574575L, 
	-5.238077571394L,  5.989339135837L, -5.223877793193L,  5.906126531298L, 
	-5.210104657506L,  5.824498766387L, -5.196741328996L,  5.744401473920L, 
	-5.183771817368L,  5.665782761184L, -5.171180926218L,  5.588593067662L, 
	-5.158954205503L,  5.512785032560L, -5.147077907351L,  5.438313371336L, 
	-5.135538944940L,  5.365134760527L, -5.124324854201L,  5.293207730229L, 
	-5.113423758116L,  5.222492563633L, -5.102824333425L,  5.152951203085L, 
	-5.092515779540L,  5.084547162172L, -5.082487789510L,  5.017245443394L, 
	-5.072730522874L,  4.951012460999L, -5.063234580265L,  4.885815968607L, 
	-5.053990979636L,  4.821624991281L, -5.044991133993L,  4.758409761714L, 
	-5.036226830279L, -4091.303858339567L, -5.027690210958L,  4.634793158995L, 
	-5.019373753305L,  4.574337767161L, -5.011270254472L,  4.514749983150L, 
	-5.003372814096L,  4.456005246139L, -4.995674819284L,  4.398079892016L, 
	-4.988169930251L,  4.340951111457L, -4.980852066814L,  4.284596910374L, 
	-4.973715395662L,  4.228996072538L, -4.966754318358L,  4.174128124260L, 
	-4.959963460033L,  4.119973300998L, -4.953337658710L,  4.066512515748L, 
	-4.946871955231L,  4.013727329129L, -4.940561583746L,  3.961599921041L, 
	-4.934401962718L,  3.910113063814L, -4.928388686431L,  3.859250096739L, 
	-4.922517516949L,  3.808994901912L, -4.916784376507L,  3.759331881303L, 
	-4.911185340317L,  3.710245934987L, -4.905716629741L,  3.661722440456L, 
	-4.900374605836L,  3.613747232960L, -4.895155763221L,  3.566306586808L, 
	-4.890056724273L,  3.519387197582L, -4.885074233611L,  3.472976165207L, 
	-4.880205152865L,  3.427060977832L, -4.875446455710L,  3.381629496469L, 
	-4.870795223146L,  3.336669940363L, -4.866248639010L,  3.292170873034L, 
	-4.861803985716L,  3.248121188965L, -4.857458640201L,  3.204510100909L, 
	-4.853210070063L,  3.161327127757L, -4.849055829895L,  3.118562082961L, 
	-4.844993557783L,  3.076205063479L, -4.841020971982L,  3.034246439195L, 
	-4.837135867745L,  2.992676842815L, -4.833336114294L,  2.951487160199L, 
	-4.829619651944L,  2.910668521110L, -4.825984489349L,  2.870212290364L, 
	-4.822428700887L,  2.830110059345L, -4.818950424149L,  2.790353637889L, 
	-4.815547857557L,  2.750935046504L, -4.812219258080L,  2.711846508907L, 
	-4.808962939056L,  2.673080444876L, -4.805777268110L,  2.634629463387L, 
	-4.802660665163L,  2.596486356033L, -4.799611600534L,  2.558644090705L, 
	-4.796628593117L,  2.521095805525L, -4.793710208643L,  2.483834803019L, 
	-4.790855058016L,  2.446854544516L, -4.788061795719L,  2.410148644769L, 
	-4.785329118289L,  2.373710866781L, -4.782655762860L,  2.337535116825L, 
	-4.780040505758L,  2.301615439662L, -4.777482161169L,  2.265946013927L, 
	-4.774979579851L,  2.230521147697L, -4.772531647904L,  2.195335274220L, 
	-4.770137285594L,  2.160382947798L, -4.767795446218L,  2.125658839822L, 
	-4.765505115023L,  2.091157734949L, -4.763265308167L,  2.056874527417L, 
	-4.761075071716L,  2.022804217493L, -4.758933480692L,  1.988941908038L, 
	-4.756839638155L,  1.955282801199L, -4.754792674315L,  1.921822195213L, 
	-4.752791745690L,  1.888555481321L, -4.750836034294L,  1.855478140783L, 
	-4.748924746854L,  1.822585742001L, -4.747057114059L,  1.789873937728L, 
	-4.745232389845L,  1.757338462379L, -4.743449850698L,  1.724975129421L, 
	-4.741708794992L,  1.692779828856L, -4.740008542348L,  1.660748524776L, 
	-4.738348433024L,  1.628877253002L, -4.736727827320L,  1.597162118797L, 
	-4.735146105017L,  1.565599294641L, -4.733602664825L,  1.534185018090L, 
	-4.732096923866L,  1.502915589688L, -4.730628317166L,  1.471787370942L, 
	-4.729196297169L,  1.440796782367L, -4.727800333280L,  1.409940301576L, 
	-4.726439911408L,  1.379214461436L, -4.725114533542L,  1.348615848268L, 
	-4.723823717334L,  1.318141100108L, -4.722566995704L,  1.287786905005L, 
	-4.721343916456L,  1.257549999375L, -4.720154041914L,  1.227427166396L, 
	-4.718996948564L,  1.197415234446L, -4.717872226720L,  1.167511075584L, 
	-4.716779480196L,  1.137711604068L, -4.715718325992L,  1.108013774914L, 
	-4.714688393997L,  1.078414582488L, -4.713689326695L,  1.048911059134L, 
	-4.712720778894L,  1.019500273838L, -4.711782417457L,  0.990179330920L, 
	-4.710873921047L,  0.960945368759L, -4.709994979883L,  0.931795558549L, 
	-4.709145295506L,  0.902727103074L, -4.708324580555L,  0.873737235527L, 
	-4.707532558549L,  0.844823218332L, -4.706768963685L,  0.815982342017L, 
	-4.706033540639L,  0.787211924083L, -4.705326044378L,  0.758509307916L, 
	-4.704646239981L,  0.729871861713L, -4.703993902467L,  0.701296977426L, 
	-4.703368816632L,  0.672782069729L, -4.702770776890L,  0.644324575003L, 
	-4.702199587131L,  0.615921950337L, -4.701655060575L,  0.587571672547L, 
	-4.701137019641L,  0.559271237209L, -4.700645295820L,  0.531018157710L, 
	-4.700179729554L,  0.502809964312L, -4.699740170124L,  0.474644203228L, 
	-4.699326475546L,  0.446518435710L, -4.698938512467L,  0.418430237152L, 
	-4.698576156074L,  0.390377196202L, -4.698239290007L,  0.362356913887L, 
	-4.697927806277L,  0.334367002739L, -4.697641605189L,  0.306405085944L, 
	-4.697380595277L,  0.278468796485L, -4.697144693238L,  0.250555776305L, 
	-4.696933823874L,  0.222663675466L, -4.696747920040L,  0.194790151322L, 
	-4.696586922600L,  0.166932867693L, -4.696450780385L,  0.139089494050L, 
	-4.696339450156L,  0.111257704693L, -4.696252896577L,  0.083435177948L, 
	-4.696191092189L,  0.055619595352L, -4.696154017393L,  0.027808640853L, 
	-4.696141660433L,  0.000000000000L, -4.696154017393L, -0.027808640853L, 
	-4.696191092189L, -0.055619595352L, -4.696252896577L, -0.083435177948L, 
	-4.696339450156L, -0.111257704693L, -4.696450780385L, -0.139089494050L, 
	-4.696586922600L, -0.166932867693L, -4.696747920040L, -0.194790151322L, 
	-4.696933823874L, -0.222663675466L, -4.697144693238L, -0.250555776305L, 
	-4.697380595277L, -0.278468796485L, -4.697641605189L, -0.306405085944L, 
	-4.697927806277L, -0.334367002739L, -4.698239290007L, -0.362356913887L, 
	-4.698576156074L, -0.390377196202L, -4.698938512467L, -0.418430237152L, 
	-4.699326475546L, -0.446518435710L, -4.699740170124L, -0.474644203228L, 
	-4.700179729554L, -0.502809964312L, -4.700645295820L, -0.531018157710L, 
	-4.701137019641L, -0.559271237209L, -4.701655060575L, -0.587571672547L, 
	-4.702199587131L, -0.615921950337L, -4.702770776890L, -0.644324575003L, 
	-4.703368816632L, -0.672782069729L, -4.703993902467L, -0.701296977426L, 
	-4.704646239981L, -0.729871861713L, -4.705326044378L, -0.758509307916L, 
	-4.706033540639L, -0.787211924083L, -4.706768963685L, -0.815982342017L, 
	-4.707532558549L, -0.844823218332L, -4.708324580555L, -0.873737235527L, 
	-4.709145295506L, -0.902727103074L, -4.709994979883L, -0.931795558549L, 
	-4.710873921047L, -0.960945368759L, -4.711782417457L, -0.990179330920L, 
	-4.712720778894L, -1.019500273838L, -4.713689326695L, -1.048911059134L, 
	-4.714688393997L, -1.078414582488L, -4.715718325992L, -1.108013774914L, 
	-4.716779480196L, -1.137711604068L, -4.717872226720L, -1.167511075584L, 
	-4.718996948564L, -1.197415234446L, -4.720154041914L, -1.227427166396L, 
	-4.721343916456L, -1.257549999375L, -4.722566995704L, -1.287786905005L, 
	-4.723823717334L, -1.318141100108L, -4.725114533542L, -1.348615848268L, 
	-4.726439911408L, -1.379214461436L, -4.727800333280L, -1.409940301576L, 
	-4.729196297169L, -1.440796782367L, -4.730628317166L, -1.471787370942L, 
	-4.732096923866L, -1.502915589688L, -4.733602664825L, -1.534185018090L, 
	-4.735146105017L, -1.565599294641L, -4.736727827320L, -1.597162118797L, 
	-4.738348433024L, -1.628877253002L, -4.740008542348L, -1.660748524776L, 
	-4.741708794992L, -1.692779828856L, -4.743449850698L, -1.724975129421L, 
	-4.745232389845L, -1.757338462379L, -4.747057114059L, -1.789873937728L, 
	-4.748924746854L, -1.822585742001L, -4.750836034294L, -1.855478140783L, 
	-4.752791745690L, -1.888555481321L, -4.754792674315L, -1.921822195213L, 
	-4.756839638155L, -1.955282801199L, -4.758933480692L, -1.988941908038L, 
	-4.761075071716L, -2.022804217493L, -4.763265308167L, -2.056874527417L, 
	-4.765505115023L, -2.091157734949L, -4.767795446218L, -2.125658839822L, 
	-4.770137285594L, -2.160382947798L, -4.772531647904L, -2.195335274220L, 
	-4.774979579851L, -2.230521147697L, -4.777482161169L, -2.265946013927L, 
	-4.780040505758L, -2.301615439662L, -4.782655762860L, -2.337535116825L, 
	-4.785329118289L, -2.373710866781L, -4.788061795719L, -2.410148644769L, 
	-4.790855058016L, -2.446854544516L, -4.793710208643L, -2.483834803019L, 
	-4.796628593117L, -2.521095805525L, -4.799611600534L, -2.558644090705L, 
	-4.802660665163L, -2.596486356033L, -4.805777268110L, -2.634629463387L, 
	-4.808962939056L, -2.673080444876L, -4.812219258080L, -2.711846508907L, 
	-4.815547857557L, -2.750935046504L, -4.818950424149L, -2.790353637889L, 
	-4.822428700887L, -2.830110059345L, -4.825984489349L, -2.870212290364L, 
	-4.829619651944L, -2.910668521110L, -4.833336114294L, -2.951487160199L, 
	-4.837135867745L, -2.992676842815L, -4.841020971982L, -3.034246439195L, 
	-4.844993557783L, -3.076205063479L, -4.849055829895L, -3.118562082961L, 
	-4.853210070063L, -3.161327127757L, -4.857458640201L, -3.204510100909L, 
	-4.861803985716L, -3.248121188965L, -4.866248639010L, -3.292170873034L, 
	-4.870795223146L, -3.336669940363L, -4.875446455710L, -3.381629496469L, 
	-4.880205152865L, -3.427060977832L, -4.885074233611L, -3.472976165207L, 
	-4.890056724273L, -3.519387197582L, -4.895155763221L, -3.566306586808L, 
	-4.900374605836L, -3.613747232960L, -4.905716629741L, -3.661722440456L, 
	-4.911185340317L, -3.710245934987L, -4.916784376507L, -3.759331881303L, 
	-4.922517516949L, -3.808994901912L, -4.928388686431L, -3.859250096739L, 
	-4.934401962718L, -3.910113063814L, -4.940561583746L, -3.961599921041L, 
	-4.946871955231L, -4.013727329129L, -4.953337658710L, -4.066512515748L, 
	-4.959963460033L, -4.119973300998L, -4.966754318358L, -4.174128124260L, 
	-4.973715395662L, -4.228996072538L, -4.980852066814L, -4.284596910374L, 
	-4.988169930251L, -4.340951111457L, -4.995674819284L, -4.398079892016L, 
	-5.003372814096L, -4.456005246139L, -5.011270254472L, -4.514749983150L, 
	-5.019373753305L, -4.574337767161L, -5.027690210958L, -4.634793158995L, 
	-5.036226830279L, 4091.303858339567L, -5.044991133993L, -4.758409761714L, 
	-5.053990979636L, -4.821624991281L, -5.063234580265L, -4.885815968607L, 
	-5.072730522874L, -4.951012460999L, -5.082487789510L, -5.017245443394L, 
	-5.092515779540L, -5.084547162172L, -5.102824333425L, -5.152951203085L, 
	-5.113423758116L, -5.222492563633L, -5.124324854201L, -5.293207730229L, 
	-5.135538944940L, -5.365134760527L, -5.147077907351L, -5.438313371336L, 
	-5.158954205503L, -5.512785032560L, -5.171180926218L, -5.588593067662L, 
	-5.183771817368L, -5.665782761184L, -5.196741328996L, -5.744401473920L, 
	-5.210104657506L, -5.824498766387L, -5.223877793193L, -5.906126531298L, 
	-5.238077571394L, -5.989339135837L, -5.252721727607L, -6.074193574575L, 
	-5.267828956919L, -6.160749633994L, -5.283418978142L, -6.249070069648L, 
	-5.299512603111L, -6.339220797142L, -5.316131811607L, -6.431271098181L, 
	-5.333299832461L, -6.525293843131L, -5.351041231423L, -6.621365731645L, 
	-5.369382006477L, -6.719567553122L, -5.388349691326L, -6.819984468915L, 
	-5.407973467878L, -6.922706318483L, -5.428284288660L, -7.027827951877L, 
	-5.449315010180L, -7.135449591277L, -5.471100538394L, -7.245677224587L, 
	-5.493677987580L, -7.358623034484L, -5.517086854064L, -7.474405866721L, 
	-5.541369206433L, -7.593151741954L, -5.566569894094L, -7.714994415925L, 
	-5.592736776257L, -7.840075993429L, -5.619920973689L, -7.968547602234L, 
	-5.648177145946L, -8.100570133907L, -5.677563797089L, -8.236315059492L, 
	-5.708143613376L, -8.375965329024L, -5.739983836855L, -8.519716365177L, 
	-5.773156679391L, -8.667777162778L, -5.807739782298L, -8.820371507639L, 
	-5.843816727518L, -8.977739330169L, -5.881477607204L, -9.140138211517L, 
	-5.920819659592L, -9.307845062794L, -5.961947980339L, -9.481158001089L, 
	-6.004976319919L, -9.660398449827L, -6.050027979452L, -9.845913495502L, 
	-6.097236819382L, -10.038078538189L, -6.146748397903L, -10.237300279565L, 
	-6.198721258962L, -10.444020099853L, -6.253328393222L, -10.658717884192L, 
	-6.310758899632L, -10.881916370002L, -6.371219880392L, -11.114186100240L, 
	-6.434938608415L, -11.356151083634L, -6.502165013983L, -11.608495282770L, 
	-6.573174546725L, -11.871970075128L, -6.648271480566L, -12.147402861998L, 
	-6.727792743591L, -12.435707037128L, -6.812112372569L, -12.737893572904L, 
	-6.901646714110L, -13.055084539285L, -6.996860522426L, -13.388528943016L, 
	-7.098274139068L, -13.739621366076L, -7.206471985169L, -14.109923998848L, 
	-7.322112654511L, -14.501192812841L, -7.445940970521L, -14.915408810723L, 
	-7.578802467458L, -15.354815542421L, -7.721660883611L, -15.821964405258L, 
	-7.875619422992L, -16.319769681535L, -8.041946767143L, -16.851575848289L, 
	-8.222109122167L, -17.421240477232L, -8.417809999249L, -18.033237109660L, 
	-8.631039995912L, -18.692783959708L, -8.864139637922L, -19.406006345721L, 
	-9.119879460529L, -20.180143637347L, -9.401563108608L, -21.023815638562L, 
	-9.713161560889L, -21.947369330027L, -10.059490017521L, -22.963335758614L, 
	-10.446444152598L, -24.087040187880L, -10.881320347795L, -25.337429053072L, 
	-11.373256922659L, -26.738209271026L, -11.933853274950L, -28.319446817872L, 
	-12.578056642227L, -30.119856148550L, -13.325461907192L, -32.190155839951L, 
	-14.202267777860L, -34.598118570985L, -15.244311555273L, -37.436405299933L, 
	-16.501946493186L, -40.835155766082L, -18.048213864782L, -44.983083661334L, 
	-19.993235640675L, -50.164629106519L, -22.511154734627L, -56.829500195394L, 
	-25.894554435549L, -65.733146563378L, -30.675754912829L, -78.249862657850L, 
	-37.935568209654L, -97.169777229013L, -50.254768090003L, -129.154881193903L, 
	-75.698370666560L, -195.023642655435L, -158.893024828945L, -409.971000100375L, 
	1172.842521981999L, 3027.431264421202L, 121.541038928366L, 313.499309501207L, 
	63.173518218082L, 162.618461027846L, 42.276560394472L, 108.453019749154L, 
	31.551284497485L, 80.536062034456L, 25.035930285296L, 63.478093559561L, 
	20.666870311751L, 51.951829827420L, 17.540256933658L, 43.623689383942L, 
	15.197669836294L, 37.309834287126L, 13.381854060381L, 32.345653658112L, 
	11.937311558717L, 28.329156861214L, 10.764542272964L, 25.002851564611L, 
	 9.796943086761L, 22.194107955330L,  8.988273755662L, 19.782798815042L, 
	 8.305450436159L, 17.682690964994L,  7.724200038581L, 15.830220483004L, 
	 7.226333028693L, 14.177444615131L,  6.797972949134L, 12.687462100144L, 
	 6.428373143706L, 11.331347879730L,  6.109105819211L, 10.086047331666L, 
	 5.833494049771L,  8.932895741241L,  5.596206378717L,  7.856555282357L, 
	 5.392962771060L,  6.844236820047L,  5.220318447882L,  5.885119650108L, 
	 5.075503288524L,  4.969910975683L,  4.956301657020L,  4.090505293377L, 
	 4.860962225119L,  3.239715861442L,  4.788130535076L,  2.411058387725L, 
	 4.736799226982L,  1.598572424669L,  4.706272395223L,  0.796669570526L, 
	 4.696141660431L,  4.773225561676L,  4.999270018078L,  5.360913781246L, 
	 5.841636125000L,  6.426286615965L,  7.103572955776L,  7.866788289600L, 
	 8.713645913102L,  9.645879262044L, 10.668939926375L, 11.791926250063L, 
	13.027794366130L, 14.393892133809L, 15.912882355397L, 17.614174598218L, 
	19.536070912827L, 21.728971307062L, 24.260225097432L, 27.221645003717L, 
	30.741511604297L, 35.004504405345L, 40.286386075022L, 47.017942200456L, 
	55.911645932667L, 68.236838783802L, 86.495900720548L, 116.401739898928L, 
	174.458182012525L, 336.235098110712L, 3246.675167331043L, 439.685358253596L, 
	209.199580583152L, 138.587607858680L, 104.312381537981L, 84.047861040269L, 
	70.649660342695L, 61.125642572856L, 54.002032228224L, 48.468709900218L, 
	44.043435203265L, 40.421200830444L, 37.399655328438L, 34.839260440491L, 
	32.640668548674L, 30.731220640553L, 29.056545012268L, 27.575141768099L, 
	26.254784334401L, 25.070064391131L, 24.000677657444L, 23.030202189503L, 
	22.145211640409L, 21.334621013994L, 20.589196768581L, 19.901185035989L, 
	19.264026011776L, 18.672132079015L, 18.120713665696L, 17.605641267580L, 
	17.123335165280L, 16.670676558780L, 16.244935417555L, 15.843711488357L, 
	15.464885742756L, 15.106580169855L, 14.767124286545L, 14.445027090702L, 
	14.138953451864L, 13.847704140794L, 13.570198859503L, 13.305461758208L, 
	13.052609023808L, 12.810838201893L, 12.579418975970L, 12.357685176774L, 
	12.145027834156L, 11.940889116021L, 11.744757024752L, 11.556160742784L, 
	11.374666536308L, 11.199874140448L, 11.031413561026L, 10.868942237847L, 
	10.712142522637L, 10.560719431538L, 10.414398637865L, 10.272924675594L, 
	10.136059328158L, 10.003580180577L,  9.875279315864L,  9.750962139172L, 
	 9.630446315267L,  9.513560806743L,  9.400145001985L,  9.290047923222L, 
	 9.183127506186L,  9.079249943916L,  8.978289088118L,  8.880125902244L, 
	 8.784647961144L,  8.691748992709L,  8.601328457422L,  8.513291162212L, 
	 8.427546905365L,  8.344010149603L,  8.262599720757L,  8.183238529700L, 
	 8.105853315482L,  8.030374407778L,  7.956735506978L,  7.884873480400L, 
	 7.814728173251L,  7.746242233114L,  7.679360946815L,  7.614032088690L, 
	 7.550205779294L,  7.487834353749L,  7.426872238945L,  7.367275838921L, 
	 7.309003427778L,  7.252015049568L,  7.196272424611L,  7.141738861775L, 
	 7.088379176276L,  7.036159612593L,  6.985047772119L,  6.935012545226L, 
	4091.306958032471L,  6.838053559605L,  6.791073470626L,  6.745057225384L, 
	 6.699979273883L,  6.655815024216L,  6.612540797993L,  6.570133788278L, 
	 6.528572019866L,  6.487834311746L,  6.447900241614L,  6.408750112302L, 
	 6.370364920007L,  6.332726324197L,  6.295816619112L,  6.259618706737L, 
	 6.224116071175L,  6.189292754333L,  6.155133332839L,  6.121622896117L, 
	 6.088747025559L,  6.056491774725L,  6.024843650512L,  5.993789595238L, 
	 5.963316969592L,  5.933413536396L,  5.904067445139L,  5.875267217235L, 
	 5.847001731976L,  5.819260213128L,  5.792032216144L,  5.765307615966L, 
	 5.739076595371L,  5.713329633842L,  5.688057496945L,  5.663251226156L, 
	 5.638902129158L,  5.615001770543L,  5.591541962924L,  5.568514758433L, 
	 5.545912440573L,  5.523727516425L,  5.501952709175L,  5.480580950960L, 
	 5.459605376012L,  5.439019314075L,  5.418816284111L,  5.398989988242L, 
	 5.379534305954L,  5.360443288526L,  5.341711153687L,  5.323332280481L, 
	 5.305301204340L,  5.287612612353L,  5.270261338711L,  5.253242360341L, 
	 5.236550792702L,  5.220181885748L,  5.204131020041L,  5.188393703019L, 
	 5.172965565401L,  5.157842357731L,  5.143019947053L,  5.128494313708L, 
	 5.114261548252L,  5.100317848495L,  5.086659516640L,  5.073282956538L, 
	 5.060184671036L,  5.047361259431L,  5.034809415011L,  5.022525922688L, 
	 5.010507656724L,  4.998751578527L,  4.987254734544L,  4.976014254217L, 
	 4.965027348021L,  4.954291305569L,  4.943803493793L,  4.933561355185L, 
	 4.923562406103L,  4.913804235141L,  4.904284501560L,  4.895000933770L, 
	 4.885951327877L,  4.877133546275L,  4.868545516295L,  4.860185228905L, 
	 4.852050737454L,  4.844140156467L,  4.836451660485L,  4.828983482947L, 
	 4.821733915116L,  4.814701305049L,  4.807884056604L,  4.801280628484L, 
	 4.794889533328L,  4.788709336826L,  4.782738656882L,  4.776976162803L, 
	 4.771420574529L,  4.766070661887L,  4.760925243888L,  4.755983188048L, 
	 4.751243409741L,  4.746704871584L,  4.742366582849L,  4.738227598903L, 
	 4.734287020683L,  4.730543994186L,  4.726997709997L,  4.723647402838L, 
	 4.720492351143L,  4.717531876661L,  4.714765344081L,  4.712192160684L, 
	 4.709811776017L,  4.707623681593L,  4.705627410612L,  4.703822537709L, 
	 4.702208678719L,  4.700785490474L,  4.699552670612L,  4.698509957416L, 
	 4.697657129671L,  4.696994006546L,  4.696520447496L,  4.696236352185L, 
	 4.696141660433L,  4.696236352185L,  4.696520447496L,  4.696994006546L, 
	 4.697657129671L,  4.698509957416L,  4.699552670612L,  4.700785490474L, 
	 4.702208678719L,  4.703822537709L,  4.705627410612L,  4.707623681593L, 
	 4.709811776017L,  4.712192160684L,  4.714765344081L,  4.717531876661L, 
	 4.720492351143L,  4.723647402838L,  4.726997709997L,  4.730543994186L, 
	 4.734287020683L,  4.738227598903L,  4.742366582849L,  4.746704871584L, 
	 4.751243409741L,  4.755983188048L,  4.760925243888L,  4.766070661887L, 
	 4.771420574529L,  4.776976162803L,  4.782738656882L,  4.788709336826L, 
	 4.794889533328L,  4.801280628484L,  4.807884056604L,  4.814701305049L, 
	 4.821733915116L,  4.828983482947L,  4.836451660485L,  4.844140156467L, 
	 4.852050737454L,  4.860185228905L,  4.868545516295L,  4.877133546275L, 
	 4.885951327877L,  4.895000933770L,  4.904284501560L,  4.913804235141L, 
	 4.923562406103L,  4.933561355185L,  4.943803493793L,  4.954291305569L, 
	 4.965027348021L,  4.976014254217L,  4.987254734544L,  4.998751578527L, 
	 5.010507656724L,  5.022525922688L,  5.034809415011L,  5.047361259431L, 
	 5.060184671036L,  5.073282956538L,  5.086659516640L,  5.100317848495L, 
	 5.114261548252L,  5.128494313708L,  5.143019947053L,  5.157842357731L, 
	 5.172965565401L,  5.188393703019L,  5.204131020041L,  5.220181885748L, 
	 5.236550792702L,  5.253242360341L,  5.270261338711L,  5.287612612353L, 
	 5.305301204340L,  5.323332280481L,  5.341711153687L,  5.360443288526L, 
	 5.379534305954L,  5.398989988242L,  5.418816284111L,  5.439019314075L, 
	 5.459605376012L,  5.480580950960L,  5.501952709175L,  5.523727516425L, 
	 5.545912440573L,  5.568514758433L,  5.591541962924L,  5.615001770543L, 
	 5.638902129158L,  5.663251226156L,  5.688057496945L,  5.713329633842L, 
	 5.739076595371L,  5.765307615966L,  5.792032216144L,  5.819260213128L, 
	 5.847001731976L,  5.875267217235L,  5.904067445139L,  5.933413536396L, 
	 5.963316969592L,  5.993789595238L,  6.024843650512L,  6.056491774725L, 
	 6.088747025559L,  6.121622896117L,  6.155133332839L,  6.189292754333L, 
	 6.224116071175L,  6.259618706737L,  6.295816619112L,  6.332726324197L, 
	 6.370364920007L,  6.408750112302L,  6.447900241614L,  6.487834311746L, 
	 6.528572019866L,  6.570133788278L,  6.612540797993L,  6.655815024216L, 
	 6.699979273883L,  6.745057225384L,  6.791073470626L,  6.838053559605L, 
	4091.306958032471L,  6.935012545226L,  6.985047772119L,  7.036159612593L, 
	 7.088379176276L,  7.141738861775L,  7.196272424611L,  7.252015049568L, 
	 7.309003427778L,  7.367275838921L,  7.426872238945L,  7.487834353749L, 
	 7.550205779294L,  7.614032088690L,  7.679360946815L,  7.746242233114L, 
	 7.814728173251L,  7.884873480400L,  7.956735506978L,  8.030374407778L, 
	 8.105853315482L,  8.183238529700L,  8.262599720757L,  8.344010149603L, 
	 8.427546905365L,  8.513291162212L,  8.601328457422L,  8.691748992709L, 
	 8.784647961144L,  8.880125902244L,  8.978289088118L,  9.079249943916L, 
	 9.183127506186L,  9.290047923222L,  9.400145001985L,  9.513560806743L, 
	 9.630446315267L,  9.750962139172L,  9.875279315864L, 10.003580180577L, 
	10.136059328158L, 10.272924675594L, 10.414398637865L, 10.560719431538L, 
	10.712142522637L, 10.868942237847L, 11.031413561026L, 11.199874140448L, 
	11.374666536308L, 11.556160742784L, 11.744757024752L, 11.940889116021L, 
	12.145027834156L, 12.357685176774L, 12.579418975970L, 12.810838201893L, 
	13.052609023808L, 13.305461758208L, 13.570198859503L, 13.847704140794L, 
	14.138953451864L, 14.445027090702L, 14.767124286545L, 15.106580169855L, 
	15.464885742756L, 15.843711488357L, 16.244935417555L, 16.670676558780L, 
	17.123335165280L, 17.605641267580L, 18.120713665696L, 18.672132079015L, 
	19.264026011776L, 19.901185035989L, 20.589196768581L, 21.334621013994L, 
	22.145211640409L, 23.030202189503L, 24.000677657444L, 25.070064391131L, 
	26.254784334401L, 27.575141768099L, 29.056545012268L, 30.731220640553L, 
	32.640668548674L, 34.839260440491L, 37.399655328438L, 40.421200830444L, 
	44.043435203265L, 48.468709900218L, 54.002032228224L, 61.125642572856L, 
	70.649660342695L, 84.047861040269L, 104.312381537981L, 138.587607858680L, 
	209.199580583152L, 439.685358253596L, 3246.675167331043L, 336.235098110712L, 
	174.458182012525L, 116.401739898928L, 86.495900720548L, 68.236838783802L, 
	55.911645932667L, 47.017942200456L, 40.286386075022L, 35.004504405345L, 
	30.741511604297L, 27.221645003717L, 24.260225097432L, 21.728971307062L, 
	19.536070912827L, 17.614174598218L, 15.912882355397L, 14.393892133809L, 
	13.027794366130L, 11.791926250063L, 10.668939926375L,  9.645879262044L, 
	 8.713645913102L,  7.866788289600L,  7.103572955776L,  6.426286615965L, 
	 5.841636125000L,  5.360913781246L,  4.999270018078L,  4.773225561676L, 
	 0.000000000000L, -0.167688599484L, -0.325477411608L, -0.466482784073L, 
	-0.587870763080L, -0.689986868908L, -0.774887056408L, -0.845189482358L, 
	-0.903442075898L, -0.951864456590L, -0.992290458918L, -1.026197134108L, 
	-1.054761412680L, -1.078918669169L, -1.099413852714L, -1.116843066525L, 
	-1.131686261983L, -1.144332544998L, -1.155099644490L, -1.164248880083L, 
	-1.171996699218L, -1.178523609967L, -1.183981136236L, -1.188497266913L, 
	-1.192180752943L, -1.195124518329L, -1.197408385600L, -1.199101267562L, 
	-1.200262940936L, -1.200945490342L, -1.201194490782L,  1.940542672177L, 
	 1.941045381828L,  1.941875040941L,  1.943003896309L,  1.944407220896L, 
	 1.946062915932L,  1.947951173628L,  1.950054190103L,  1.952355920088L, 
	 1.954841866528L,  1.957498899481L,  1.960315099681L,  1.963279622973L, 
	 1.966382582451L,  1.969614945682L,  1.972968444822L,  1.976435497787L, 
	 1.980009138922L,  1.983682957892L,  1.987451045647L,  1.991307946568L, 
	 1.995248615956L,  1.999268382205L,  2.003362913051L,  2.007528185422L, 
	 2.011760458418L,  2.016056249080L,  2.020412310595L,  2.024825612672L, 
	 2.029293323841L,  2.033812795443L,  2.038381547152L,  2.042997253838L, 
	 2.047657733641L,  2.052360937127L,  2.057104937408L,  2.061887921135L, 
	 2.066708180270L,  2.071564104561L,  2.076454174652L,  2.081376955768L, 
	 2.086331091917L,  2.091315300560L,  2.096328367708L,  2.101369143407L, 
	 2.106436537572L,  2.111529516146L,  2.116647097542L,  2.121788349363L, 
	 2.126952385354L,  2.132138362587L,  2.137345478841L,  2.142572970174L, 
	 2.147820108668L,  2.153086200323L,  2.158370583111L,  2.163672625146L, 
	 2.168991722989L,  2.174327300063L,  2.179678805173L,  2.185045711118L, 
	 2.190427513403L,  2.195823729022L,  2.201233895323L,  2.206657568948L, 
	 2.212094324831L,  2.217543755264L,  2.223005469013L,  2.228479090496L, 
	 2.233964259000L,  2.239460627954L,  2.244967864235L,  2.250485647522L, 
	 2.256013669680L,  2.261551634189L,  2.267099255590L,  2.272656258978L, 
	 2.278222379512L,  2.283797361955L,  2.289380960241L,  2.294972937063L, 
	 2.300573063479L,  2.306181118552L,  2.311796888992L,  2.317420168827L, 
	 2.323050759090L,  2.328688467519L,  2.334333108274L,  2.339984501666L, 
	 2.345642473903L,  2.351306856846L,  2.356977487781L,  2.362654209190L, 
	 2.368336868552L,  2.374025318135L,  2.379719414812L,  2.385419019877L, 
	-1.572027285057L,  2.396834221387L,  2.402549561030L,  2.408269895099L, 
	 2.413995104555L,  2.419725073853L,  2.425459690814L,  2.431198846500L, 
	 2.436942435090L,  2.442690353773L,  2.448442502634L,  2.454198784548L, 
	 2.459959105083L,  2.465723372405L,  2.471491497180L,  2.477263392492L, 
	 2.483038973756L,  2.488818158637L,  2.494600866972L,  2.500387020695L, 
	 2.506176543769L,  2.511969362109L,  2.517765403528L,  2.523564597661L, 
	 2.529366875914L,  2.535172171399L,  2.540980418882L,  2.546791554724L, 
	 2.552605516835L,  2.558422244618L,  2.564241678926L,  2.570063762010L, 
	 2.575888437478L,  2.581715650253L,  2.587545346528L,  2.593377473726L, 
	 2.599211980465L,  2.605048816519L,  2.610887932780L,  2.616729281225L, 
	 2.622572814885L,  2.628418487809L,  2.634266255035L,  2.640116072558L, 
	 2.645967897303L,  2.651821687097L,  2.657677400641L,  2.663534997482L, 
	 2.669394437991L,  2.675255683337L,  2.681118695464L,  2.686983437066L, 
	 2.692849871566L,  2.698717963096L,  2.704587676474L,  2.710458977185L, 
	 2.716331831360L,  2.722206205761L,  2.728082067756L,  2.733959385309L, 
	 2.739838126956L,  2.745718261793L,  2.751599759456L,  2.757482590110L, 
	 2.763366724427L,  2.769252133578L,  2.775138789216L,  2.781026663458L, 
	 2.786915728879L,  2.792805958493L,  2.798697325741L,  2.804589804481L, 
	 2.810483368974L,  2.816377993870L,  2.822273654203L,  2.828170325373L, 
	 2.834067983137L,  2.839966603602L,  2.845866163208L,  2.851766638724L, 
	 2.857668007235L,  2.863570246134L,  2.869473333111L,  2.875377246143L, 
	 2.881281963489L,  2.887187463679L,  2.893093725502L,  2.899000728005L, 
	 2.904908450479L,  2.910816872451L,  2.916725973683L,  2.922635734154L, 
	 2.928546134061L,  2.934457153808L,  2.940368774000L,  2.946280975434L, 
	 2.952193739094L,  2.958107046144L,  2.964020877922L,  2.969935215930L, 
	 2.975850041832L,  2.981765337446L,  2.987681084736L,  2.993597265809L, 
	 2.999513862907L,  3.005430858401L,  3.011348234787L,  3.017265974677L, 
	 3.023184060797L,  3.029102475979L,  3.035021203156L,  3.040940225359L, 
	 3.046859525705L,  3.052779087400L,  3.058698893727L,  3.064618928046L, 
	 3.070539173784L,  3.076459614434L,  3.082380233546L,  3.088301014725L, 
	 3.094221941627L,  3.100142997950L,  3.106064167430L,  3.111985433839L, 
	 3.117906780977L,  3.123828192671L,  3.129749652763L,  3.135671145113L, 
	 3.141592653590L, -3.135671145113L, -3.129749652763L, -3.123828192671L, 
	-3.117906780977L, -3.111985433839L, -3.106064167430L, -3.100142997950L, 
	-3.094221941627L, -3.088301014725L, -3.082380233546L, -3.076459614434L, 
	-3.070539173784L, -3.064618928046L, -3.058698893727L, -3.052779087400L, 
	-3.046859525705L, -3.040940225359L, -3.035021203156L, -3.029102475979L, 
	-3.023184060797L, -3.017265974677L, -3.011348234787L, -3.005430858401L, 
	-2.999513862907L, -2.993597265809L, -2.987681084736L, -2.981765337446L, 
	-2.975850041832L, -2.969935215930L, -2.964020877922L, -2.958107046144L, 
	-2.952193739094L, -2.946280975434L, -2.940368774000L, -2.934457153808L, 
	-2.928546134061L, -2.922635734154L, -2.916725973683L, -2.910816872451L, 
	-2.904908450479L, -2.899000728005L, -2.893093725502L, -2.887187463679L, 
	-2.881281963489L, -2.875377246143L, -2.869473333111L, -2.863570246134L, 
	-2.857668007235L, -2.851766638724L, -2.845866163208L, -2.839966603602L, 
	-2.834067983137L, -2.828170325373L, -2.822273654203L, -2.816377993870L, 
	-2.810483368974L, -2.804589804481L, -2.798697325741L, -2.792805958493L, 
	-2.786915728879L, -2.781026663458L, -2.775138789216L, -2.769252133578L, 
	-2.763366724427L, -2.757482590110L, -2.751599759456L, -2.745718261793L, 
	-2.739838126956L, -2.733959385309L, -2.728082067756L, -2.722206205761L, 
	-2.716331831360L, -2.710458977185L, -2.704587676474L, -2.698717963096L, 
	-2.692849871566L, -2.686983437066L, -2.681118695464L, -2.675255683337L, 
	-2.669394437991L, -2.663534997482L, -2.657677400641L, -2.651821687097L, 
	-2.645967897303L, -2.640116072558L, -2.634266255035L, -2.628418487809L, 
	-2.622572814885L, -2.616729281225L, -2.610887932780L, -2.605048816519L, 
	-2.599211980465L, -2.593377473726L, -2.587545346528L, -2.581715650253L, 
	-2.575888437478L, -2.570063762010L, -2.564241678926L, -2.558422244618L, 
	-2.552605516835L, -2.546791554724L, -2.540980418882L, -2.535172171399L, 
	-2.529366875914L, -2.523564597661L, -2.517765403528L, -2.511969362109L, 
	-2.506176543769L, -2.500387020695L, -2.494600866972L, -2.488818158637L, 
	-2.483038973756L, -2.477263392492L, -2.471491497180L, -2.465723372405L, 
	-2.459959105083L, -2.454198784548L, -2.448442502634L, -2.442690353773L, 
	-2.436942435090L, -2.431198846500L, -2.425459690814L, -2.419725073853L, 
	-2.413995104555L, -2.408269895099L, -2.402549561030L, -2.396834221387L, 
	 1.572027285057L, -2.385419019877L, -2.379719414812L, -2.374025318135L, 
	-2.368336868552L, -2.362654209190L, -2.356977487781L, -2.351306856846L, 
	-2.345642473903L, -2.339984501666L, -2.334333108274L, -2.328688467519L, 
	-2.323050759090L, -2.317420168827L, -2.311796888992L, -2.306181118552L, 
	-2.300573063479L, -2.294972937063L, -2.289380960241L, -2.283797361955L, 
	-2.278222379512L, -2.272656258978L, -2.267099255590L, -2.261551634189L, 
	-2.256013669680L, -2.250485647522L, -2.244967864235L, -2.239460627954L, 
	-2.233964259000L, -2.228479090496L, -2.223005469013L, -2.217543755264L, 
	-2.212094324831L, -2.206657568948L, -2.201233895323L, -2.195823729022L, 
	-2.190427513403L, -2.185045711118L, -2.179678805173L, -2.174327300063L, 
	-2.168991722989L, -2.163672625146L, -2.158370583111L, -2.153086200323L, 
	-2.147820108668L, -2.142572970174L, -2.137345478841L, -2.132138362587L, 
	-2.126952385354L, -2.121788349363L, -2.116647097542L, -2.111529516146L, 
	-2.106436537572L, -2.101369143407L, -2.096328367708L, -2.091315300560L, 
	-2.086331091917L, -2.081376955768L, -2.076454174652L, -2.071564104561L, 
	-2.066708180270L, -2.061887921135L, -2.057104937408L, -2.052360937127L, 
	-2.047657733641L, -2.042997253838L, -2.038381547152L, -2.033812795443L, 
	-2.029293323841L, -2.024825612672L, -2.020412310595L, -2.016056249080L, 
	-2.011760458418L, -2.007528185422L, -2.003362913051L, -1.999268382205L, 
	-1.995248615956L, -1.991307946568L, -1.987451045647L, -1.983682957892L, 
	-1.980009138922L, -1.976435497787L, -1.972968444822L, -1.969614945682L, 
	-1.966382582451L, -1.963279622973L, -1.960315099681L, -1.957498899481L, 
	-1.954841866528L, -1.952355920088L, -1.950054190103L, -1.947951173628L, 
	-1.946062915932L, -1.944407220896L, -1.943003896309L, -1.941875040941L, 
	-1.941045381828L, -1.940542672177L,  1.201194490782L,  1.200945490342L, 
	 1.200262940936L,  1.199101267562L,  1.197408385600L,  1.195124518329L, 
	 1.192180752943L,  1.188497266913L,  1.183981136236L,  1.178523609967L, 
	 1.171996699218L,  1.164248880083L,  1.155099644490L,  1.144332544998L, 
	 1.131686261983L,  1.116843066525L,  1.099413852714L,  1.078918669169L, 
	 1.054761412680L,  1.026197134108L,  0.992290458918L,  0.951864456590L, 
	 0.903442075898L,  0.845189482358L,  0.774887056408L,  0.689986868908L, 
	 0.587870763080L,  0.466482784073L,  0.325477411608L,  0.167688599484L, 
}; 



// End of File
