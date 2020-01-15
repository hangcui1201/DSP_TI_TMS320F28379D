//#############################################################################
//! \file golden.c
//! \brief  Division Ouput Vector (512) 
//! \author Vishal Coelho 
//! \date   21-Sep-2016
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

#include "fastrts.h"

const float32_t test_golden[512] = {
    -1.359140914230e+00F, -1.360116561582e+00F, -1.361093016247e+00F, 
    -1.362070279226e+00F, -1.363048351524e+00F, -1.364027234147e+00F, 
    -1.365006928102e+00F, -1.365987434397e+00F, -1.366968754045e+00F, 
    -1.367950888056e+00F, -1.368933837446e+00F, -1.369917603231e+00F, 
    -1.370902186427e+00F, -1.371887588054e+00F, -1.372873809133e+00F, 
    -1.373860850686e+00F, -1.374848713738e+00F, -1.375837399315e+00F, 
    -1.376826908445e+00F, -1.377817242156e+00F, -1.378808401481e+00F, 
    -1.379800387451e+00F, -1.380793201102e+00F, -1.381786843470e+00F, 
    -1.382781315592e+00F, -1.383776618510e+00F, -1.384772753263e+00F, 
    -1.385769720896e+00F, -1.386767522453e+00F, -1.387766158982e+00F, 
    -1.388765631530e+00F, -1.389765941148e+00F, -1.390767088889e+00F, 
    -1.391769075805e+00F, -1.392771902952e+00F, -1.393775571388e+00F, 
    -1.394780082172e+00F, -1.395785436365e+00F, -1.396791635029e+00F, 
    -1.397798679228e+00F, -1.398806570030e+00F, -1.399815308502e+00F, 
    -1.400824895713e+00F, -1.401835332736e+00F, -1.402846620644e+00F, 
    -1.403858760512e+00F, -1.404871753418e+00F, -1.405885600439e+00F, 
    -1.406900302657e+00F, -1.407915861155e+00F, -1.408932277016e+00F, 
    -1.409949551327e+00F, -1.410967685176e+00F, -1.411986679652e+00F, 
    -1.413006535848e+00F, -1.414027254857e+00F, -1.415048837774e+00F, 
    -1.416071285697e+00F, -1.417094599724e+00F, -1.418118780958e+00F, 
    -1.419143830499e+00F, -1.420169749454e+00F, -1.421196538928e+00F, 
    -1.422224200031e+00F, -1.423252733872e+00F, -1.424282141564e+00F, 
    -1.425312424221e+00F, -1.426343582958e+00F, -1.427375618895e+00F, 
    -1.428408533150e+00F, -1.429442326846e+00F, -1.430477001105e+00F, 
    -1.431512557054e+00F, -1.432548995821e+00F, -1.433586318533e+00F, 
    -1.434624526323e+00F, -1.435663620325e+00F, -1.436703601672e+00F, 
    -1.437744471503e+00F, -1.438786230956e+00F, -1.439828881172e+00F, 
    -1.440872423295e+00F, -1.441916858469e+00F, -1.442962187841e+00F, 
    -1.444008412560e+00F, -1.445055533777e+00F, -1.446103552645e+00F, 
    -1.447152470318e+00F, -1.448202287953e+00F, -1.449253006709e+00F, 
    -1.450304627746e+00F, -1.451357152228e+00F, -1.452410581319e+00F, 
    -1.453464916186e+00F, -1.454520157997e+00F, -1.455576307923e+00F, 
    -1.456633367138e+00F, -1.457691336815e+00F, -1.458750218131e+00F, 
    -1.459810012266e+00F, -1.460870720401e+00F, -1.461932343717e+00F, 
    -1.462994883401e+00F, -1.464058340638e+00F, -1.465122716619e+00F, 
    -1.466188012534e+00F, -1.467254229577e+00F, -1.468321368942e+00F, 
    -1.469389431826e+00F, -1.470458419431e+00F, -1.471528332955e+00F, 
    -1.472599173605e+00F, -1.473670942583e+00F, -1.474743641100e+00F, 
    -1.475817270364e+00F, -1.476891831587e+00F, -1.477967325983e+00F, 
    -1.479043754768e+00F, -1.480121119162e+00F, -1.481199420383e+00F, 
    -1.482278659654e+00F, -1.483358838200e+00F, -1.484439957249e+00F, 
    -1.485522018027e+00F, -1.486605021767e+00F, -1.487688969702e+00F, 
    -1.488773863067e+00F, -1.489859703100e+00F, -1.490946491039e+00F, 
    -1.492034228128e+00F, -1.493122915609e+00F, -1.494212554729e+00F, 
    -1.495303146737e+00F, -1.496394692882e+00F, -1.497487194418e+00F, 
    -1.498580652599e+00F, -1.499675068683e+00F, -1.500770443928e+00F, 
    -1.501866779596e+00F, -1.502964076952e+00F, -1.504062337260e+00F, 
    -1.505161561789e+00F, -1.506261751809e+00F, -1.507362908593e+00F, 
    -1.508465033416e+00F, -1.509568127555e+00F, -1.510672192289e+00F, 
    -1.511777228900e+00F, -1.512883238671e+00F, -1.513990222889e+00F, 
    -1.515098182842e+00F, -1.516207119821e+00F, -1.517317035118e+00F, 
    -1.518427930030e+00F, -1.519539805852e+00F, -1.520652663885e+00F, 
    -1.521766505432e+00F, -1.522881331796e+00F, -1.523997144285e+00F, 
    -1.525113944206e+00F, -1.526231732872e+00F, -1.527350511597e+00F, 
    -1.528470281695e+00F, -1.529591044486e+00F, -1.530712801290e+00F, 
    -1.531835553430e+00F, -1.532959302231e+00F, -1.534084049021e+00F, 
    -1.535209795131e+00F, -1.536336541892e+00F, -1.537464290639e+00F, 
    -1.538593042710e+00F, -1.539722799444e+00F, -1.540853562183e+00F, 
    -1.541985332271e+00F, -1.543118111055e+00F, -1.544251899884e+00F, 
    -1.545386700110e+00F, -1.546522513086e+00F, -1.547659340169e+00F, 
    -1.548797182717e+00F, -1.549936042092e+00F, -1.551075919658e+00F, 
    -1.552216816780e+00F, -1.553358734828e+00F, -1.554501675171e+00F, 
    -1.555645639184e+00F, -1.556790628242e+00F, -1.557936643724e+00F, 
    -1.559083687010e+00F, -1.560231759484e+00F, -1.561380862531e+00F, 
    -1.562530997541e+00F, -1.563682165902e+00F, -1.564834369010e+00F, 
    -1.565987608260e+00F, -1.567141885049e+00F, -1.568297200779e+00F, 
    -1.569453556853e+00F, -1.570610954677e+00F, -1.571769395660e+00F, 
    -1.572928881211e+00F, -1.574089412746e+00F, -1.575250991679e+00F, 
    -1.576413619429e+00F, -1.577577297418e+00F, -1.578742027069e+00F, 
    -1.579907809808e+00F, -1.581074647065e+00F, -1.582242540270e+00F, 
    -1.583411490858e+00F, -1.584581500266e+00F, -1.585752569933e+00F, 
    -1.586924701300e+00F, -1.588097895812e+00F, -1.589272154916e+00F, 
    -1.590447480062e+00F, -1.591623872702e+00F, -1.592801334292e+00F, 
    -1.593979866288e+00F, -1.595159470152e+00F, -1.596340147345e+00F, 
    -1.597521899335e+00F, -1.598704727588e+00F, -1.599888633576e+00F, 
    -1.601073618773e+00F, -1.602259684655e+00F, -1.603446832700e+00F, 
    -1.604635064392e+00F, -1.605824381213e+00F, -1.607014784652e+00F, 
    -1.608206276198e+00F, -1.609398857343e+00F, -1.610592529583e+00F, 
    -1.611787294417e+00F, -1.612983153344e+00F, -1.614180107869e+00F, 
    -1.615378159497e+00F, -1.616577309738e+00F, -1.617777560104e+00F, 
    -1.618978912109e+00F, -1.620181367270e+00F, -1.621384927109e+00F, 
    -1.622589593146e+00F, -1.623795366910e+00F, -1.625002249928e+00F, 
    -1.626210243731e+00F, -1.627419349853e+00F, -1.628629569833e+00F, 
    -1.629840905209e+00F, -1.631053357525e+00F, -1.632266928325e+00F, 
    -1.633481619159e+00F, -1.634697431577e+00F, -1.635914367134e+00F, 
    -1.637132427387e+00F, -1.638351613895e+00F, -1.639571928222e+00F, 
    -1.640793371933e+00F, -1.642015946597e+00F, -1.643239653784e+00F, 
    -1.644464495070e+00F, -1.645690472033e+00F, -1.646917586251e+00F, 
    -1.648145839308e+00F, -1.649375232791e+00F, -1.650605768288e+00F, 
    -1.651837447391e+00F, -1.653070271696e+00F, -1.654304242800e+00F, 
    -1.655539362304e+00F, -1.656775631813e+00F, -1.658013052932e+00F, 
    -1.659251627272e+00F, -1.660491356446e+00F, -1.661732242070e+00F, 
    -1.662974285762e+00F, -1.664217489145e+00F, -1.665461853843e+00F, 
    -1.666707381484e+00F, -1.667954073700e+00F, -1.669201932124e+00F, 
    -1.670450958394e+00F, -1.671701154150e+00F, -1.672952521035e+00F, 
    -1.674205060696e+00F, -1.675458774781e+00F, -1.676713664944e+00F, 
    -1.677969732841e+00F, -1.679226980129e+00F, -1.680485408471e+00F, 
    -1.681745019532e+00F, -1.683005814979e+00F, -1.684267796485e+00F, 
    -1.685530965724e+00F, -1.686795324373e+00F, -1.688060874113e+00F, 
    -1.689327616627e+00F, -1.690595553604e+00F, -1.691864686732e+00F, 
    -1.693135017706e+00F, -1.694406548223e+00F, -1.695679279981e+00F, 
    -1.696953214685e+00F, -1.698228354040e+00F, -1.699504699756e+00F, 
    -1.700782253545e+00F, -1.702061017125e+00F, -1.703340992213e+00F, 
    -1.704622180533e+00F, -1.705904583810e+00F, -1.707188203773e+00F, 
    -1.708473042155e+00F, -1.709759100691e+00F, -1.711046381120e+00F, 
    -1.712334885184e+00F, -1.713624614630e+00F, -1.714915571205e+00F, 
    -1.716207756661e+00F, -1.717501172756e+00F, -1.718795821246e+00F, 
    -1.720091703896e+00F, -1.721388822469e+00F, -1.722687178735e+00F, 
    -1.723986774467e+00F, -1.725287611440e+00F, -1.726589691433e+00F, 
    -1.727893016228e+00F, -1.729197587613e+00F, -1.730503407375e+00F, 
    -1.731810477308e+00F, -1.733118799208e+00F, -1.734428374875e+00F, 
    -1.735739206111e+00F, -1.737051294724e+00F, -1.738364642523e+00F, 
    -1.739679251321e+00F, -1.740995122937e+00F, -1.742312259189e+00F, 
    -1.743630661903e+00F, -1.744950332905e+00F, -1.746271274028e+00F, 
    -1.747593487104e+00F, -1.748916973972e+00F, -1.750241736475e+00F, 
    -1.751567776456e+00F, -1.752895095765e+00F, -1.754223696254e+00F, 
    -1.755553579779e+00F, -1.756884748199e+00F, -1.758217203378e+00F, 
    -1.759550947182e+00F, -1.760885981481e+00F, -1.762222308149e+00F, 
    -1.763559929064e+00F, -1.764898846106e+00F, -1.766239061161e+00F, 
    -1.767580576118e+00F, -1.768923392867e+00F, -1.770267513305e+00F, 
    -1.771612939332e+00F, -1.772959672851e+00F, -1.774307715767e+00F, 
    -1.775657069993e+00F, -1.777007737443e+00F, -1.778359720033e+00F, 
    -1.779713019687e+00F, -1.781067638329e+00F, -1.782423577890e+00F, 
    -1.783780840301e+00F, -1.785139427500e+00F, -1.786499341427e+00F, 
    -1.787860584027e+00F, -1.789223157248e+00F, -1.790587063042e+00F, 
    -1.791952303364e+00F, -1.793318880174e+00F, -1.794686795437e+00F, 
    -1.796056051118e+00F, -1.797426649190e+00F, -1.798798591627e+00F, 
    -1.800171880408e+00F, -1.801546517516e+00F, -1.802922504938e+00F, 
    -1.804299844664e+00F, -1.805678538689e+00F, -1.807058589012e+00F, 
    -1.808439997634e+00F, -1.809822766562e+00F, -1.811206897806e+00F, 
    -1.812592393381e+00F, -1.813979255305e+00F, -1.815367485600e+00F, 
    -1.816757086292e+00F, -1.818148059411e+00F, -1.819540406992e+00F, 
    -1.820934131072e+00F, -1.822329233695e+00F, -1.823725716905e+00F, 
    -1.825123582755e+00F, -1.826522833298e+00F, -1.827923470592e+00F, 
    -1.829325496700e+00F, -1.830728913689e+00F, -1.832133723630e+00F, 
    -1.833539928597e+00F, -1.834947530669e+00F, -1.836356531931e+00F, 
    -1.837766934468e+00F, -1.839178740372e+00F, -1.840591951739e+00F, 
    -1.842006570669e+00F, -1.843422599265e+00F, -1.844840039636e+00F, 
    -1.846258893894e+00F, -1.847679164156e+00F, -1.849100852543e+00F, 
    -1.850523961178e+00F, -1.851948492193e+00F, -1.853374447720e+00F, 
    -1.854801829897e+00F, -1.856230640866e+00F, -1.857660882774e+00F, 
    -1.859092557771e+00F, -1.860525668012e+00F, -1.861960215657e+00F, 
    -1.863396202870e+00F, -1.864833631817e+00F, -1.866272504672e+00F, 
    -1.867712823611e+00F, -1.869154590816e+00F, -1.870597808471e+00F, 
    -1.872042478768e+00F, -1.873488603899e+00F, -1.874936186064e+00F, 
    -1.876385227466e+00F, -1.877835730313e+00F, -1.879287696816e+00F, 
    -1.880741129192e+00F, -1.882196029662e+00F, -1.883652400451e+00F, 
    -1.885110243791e+00F, -1.886569561914e+00F, -1.888030357060e+00F, 
    -1.889492631473e+00F, -1.890956387400e+00F, -1.892421627095e+00F, 
    -1.893888352814e+00F, -1.895356566819e+00F, -1.896826271378e+00F, 
    -1.898297468760e+00F, -1.899770161241e+00F, -1.901244351102e+00F, 
    -1.902720040627e+00F, -1.904197232107e+00F, -1.905675927834e+00F, 
    -1.907156130109e+00F, -1.908637841234e+00F, -1.910121063518e+00F, 
    -1.911605799274e+00F, -1.913092050820e+00F, -1.914579820478e+00F, 
    -1.916069110574e+00F, -1.917559923442e+00F, -1.919052261418e+00F, 
    -1.920546126842e+00F, -1.922041522063e+00F, -1.923538449430e+00F, 
    -1.925036911299e+00F, -1.926536910032e+00F, -1.928038447994e+00F, 
    -1.929541527554e+00F, -1.931046151090e+00F, -1.932552320980e+00F, 
    -1.934060039611e+00F, -1.935569309371e+00F, -1.937080132656e+00F, 
    -1.938592511866e+00F, -1.940106449405e+00F, -1.941621947683e+00F, 
    -1.943139009115e+00F, -1.944657636121e+00F, -1.946177831126e+00F, 
    -1.947699596558e+00F, -1.949222934854e+00F, -1.950747848451e+00F, 
    -1.952274339797e+00F, -1.953802411339e+00F, -1.955332065534e+00F, 
    -1.956863304841e+00F, -1.958396131726e+00F, -1.959930548659e+00F, 
    -1.961466558114e+00F, -1.963004162573e+00F, -1.964543364522e+00F, 
    -1.966084166450e+00F, -1.967626570855e+00F, -1.969170580238e+00F, 
    -1.970716197104e+00F, -1.972263423966e+00F, -1.973812263340e+00F, 
    -1.975362717749e+00F, -1.976914789720e+00F, -1.978468481785e+00F, 
    -1.980023796484e+00F, -1.981580736358e+00F, -1.983139303956e+00F, 
    -1.984699501834e+00F, -1.986261332548e+00F, -1.987824798666e+00F, 
    -1.989389902755e+00F, -1.990956647392e+00F, }; 

// End of File