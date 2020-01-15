//#############################################################################
//! \file   input.c
//! \brief  Input Vector (1024) 
//! \author Vishal Coelho 
//! \date   16-Sep-2016
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

#ifdef __cplusplus
#pragma DATA_SECTION("FFT_buffer_1")
#else
#pragma DATA_SECTION(test_input, "FFT_buffer_1")
#endif
float test_input[512] = {
   0.000000000000F,   14.897492923984F,   28.260433261500F,   38.727975664427F,
  45.265651596881F,   47.278624644876F,   44.672131507560F,   37.852355059237F,
  27.668431730895F,   15.303598647584F,    2.129699197772F,  -10.456400706358F,
 -21.194018816910F,  -29.097742341332F,  -33.557886365955F,  -34.391111788306F,
 -31.836622908295F,  -26.500451483296F,  -19.256939264782F,  -11.121795547842F,
  -3.114359726616F,    3.872452941362F,    9.177669594920F,   12.440225318308F,
  13.621850226095F,   12.983727842774F,   11.022155471613F,    8.373955672204F,
   5.706304504885F,    3.607445098791F,    2.494227674883F,    2.549664674798F,
   3.699122229152F,    5.628043281936F,    7.838024235031F,    9.732499079456F,
  10.719000252122F,   10.312559293011F,    8.224614601737F,    4.423831537767F,
  -0.840775828588F,   -7.058660099302F,  -13.516723640523F,  -19.390896376067F,
 -23.857950517048F,  -26.212103530532F,  -25.970005961553F,  -22.949040566734F,
 -17.307306513216F,   -9.538766691219F,   -0.423105946034F,    9.063945247308F,
  17.868575793437F,   24.989885223814F,   29.606659020464F,   31.183029957799F,
  29.538766665749F,   24.874523187632F,   17.748319282590F,    9.006004482629F,
  -0.325385387455F,   -9.167477337174F,  -16.526564851992F,  -21.617844301178F,
 -23.961498282801F,  -23.437985040022F,  -20.295349660991F,  -15.107809834156F,
  -8.691419792033F,   -1.988395394576F,    4.064093101168F,    8.662762620272F,
  11.247125904431F,   11.573615717286F,    9.744814027711F,    6.189805866372F,
   1.598370834755F,   -3.181924586243F,   -7.271527366720F,   -9.890151932878F,
 -10.475176540290F,   -8.770490510444F,   -4.873008643892F,    0.770249379814F,
   7.414918288997F,   14.115471537666F,   19.852400405388F,   23.673559135333F,
  24.830671875821F,   22.892354996703F,   17.817872191718F,    9.980846970709F,
   0.138656638402F,  -10.649630016338F,  -21.147075534707F,  -30.089139728917F,
 -36.341412521319F,  -39.044635253811F,  -37.728257371678F,  -32.377652805052F,
 -23.445950844743F,  -11.808462954053F,    1.335004983252F,   14.598027755752F,
  26.568591713360F,   35.973339636709F,   41.824743110147F,   43.533171207938F,
  40.970373367140F,   34.477132356729F,   24.814948121700F,   13.068655266496F,
   0.512942218019F,  -11.539948605617F,  -21.892041973290F,  -29.592180657696F,
 -34.033440101603F,  -35.004464260961F,  -32.690018465298F,  -27.622761877982F,
 -20.594519607683F,  -12.540355683419F,   -4.411866671986F,    2.943048893288F,
   8.878204426688F,   13.012792801496F,   15.253751113680F,   15.775861908374F,
  14.964605236950F,   13.331902151672F,   11.418466750445F,    9.698032948493F,
   8.498053359763F,    7.948702207597F,    7.967566117518F,    8.281923860989F,
   8.484789162770F,    8.115742099702F,    6.753744044033F,    4.107171948383F,
   0.086509694499F,   -5.152517871102F,  -11.203407423061F,  -17.443551992740F,
 -23.105832308486F,  -27.378264746575F,  -29.518425586194F,  -28.966739558249F,
 -25.442280927279F,  -19.006590801396F,  -10.084951002421F,    0.559932469643F,
  11.900524456001F,   22.755674134463F,   31.927317946126F,   38.345714060248F,
  41.204611058414F,   40.068563951507F,   34.937804198549F,   26.261258767169F,
  14.894835673395F,    2.009102819496F,  -11.042938040428F,  -22.882012667081F,
 -32.263448533056F,  -38.222747481694F,  -40.187635719277F,  -38.042531568065F,
 -32.137370636776F,  -23.239789419771F,  -12.436873228972F,   -0.999082436115F,
   9.776255346728F,   18.721983990981F,   24.938854791587F,   27.896766901301F,
  27.487179779447F,   24.020800456656F,   18.171808030739F,   10.876817566446F,
   3.202593160886F,   -3.799564083177F,   -9.233309137456F,  -12.472248650865F,
 -13.235552186173F,  -11.614730565817F,   -8.048781647415F,   -3.251869142915F,
   1.895950141912F,    6.479546371922F,    9.682897777653F,   10.908132493797F,
   9.863113691282F,    6.605624268202F,    1.538173389222F,   -4.645804331458F,
 -11.056966903025F,  -16.733310892483F,  -20.774826962361F,  -22.471198057827F,
 -21.405106187662F,  -17.516995362145F,  -11.122320442708F,   -2.878692348943F,
   6.292951462720F,   15.322869161539F,   23.127683226626F,   28.748408766266F,
  31.473196942119F,   30.928712732087F,   27.128264339162F,   20.470561502665F,
  11.689522374690F,    1.761993030627F,   -8.214272272114F,  -17.156226367350F,
 -24.126985354378F,  -28.446143484911F,  -29.764996213238F,  -28.097583321893F,
 -23.804484471590F,  -17.532653246300F,  -10.120399080078F,   -2.481134312711F,
   4.517903933125F,   10.165404404083F,   13.989582747777F,   15.804926867096F,
  15.716723445513F,   14.084020360234F,   11.447531709168F,    8.433864582591F,
   5.650664962350F,    3.588401714034F,    2.543382911519F,    2.573391452897F,
   3.492491599889F,    4.905777235796F,    6.278922600122F,    7.032194200442F,
   6.644830470549F,    4.753936876122F,    1.232546867284F,   -3.765782291564F,
  -9.803890672241F,  -16.201684589905F,  -22.116519350024F,  -26.653423340787F,
 -28.990700551921F,  -28.503767226416F,  -24.869713444092F,  -18.137127413877F,
  -8.749946019168F,    2.480033883823F,   14.450597841431F,   25.888388634288F,
  35.496078650322F,   42.109408608588F,   44.844258945773F,   43.214689176485F,
  37.206160034722F,   27.293548437789F,   14.400397357030F,   -0.196763743152F,
 -15.008194248516F,  -28.498290428813F,  -39.260350196189F,  -46.177505982129F,
 -48.550179261558F,  -46.174511153681F,  -39.362301507219F,  -28.900264488918F,
 -15.953946756754F,   -1.928486484189F,   11.696356760908F,   23.536466407738F,
  32.458106206714F,   37.698570157832F,   38.938777530062F,   36.320152963904F,
  30.405318203784F,   22.089244861515F,   12.473651897474F,    2.721792113011F,
  -6.087183912479F,  -13.085601123520F,  -17.710626703802F,  -19.752835473055F,
 -19.355443883284F,  -16.966404472822F,  -13.251823956257F,   -8.984153564490F,
  -4.921648750390F,   -1.696325982053F,    0.274005023320F,    0.837822480107F,
   0.119613253646F,   -1.513089831632F,   -3.519572677821F,   -5.281713141866F,
  -6.211065423786F,   -5.851150969479F,   -3.959636340259F,   -0.558033423281F,
   4.058740373368F,    9.354817824102F,   14.623670448961F,   19.086563709878F,
  22.005372831940F,   22.793738318022F,   21.110565347645F,   16.922141878023F,
  10.523361158646F,    2.514111239189F,   -6.266927888786F,  -14.842910149888F,
 -22.220843126178F,  -27.518857961823F,  -30.081655802621F,  -29.568453879596F,
 -26.001301664897F,  -19.766864335651F,  -11.570974298544F,   -2.351592430224F,
   6.838562858786F,   14.964335534693F,   21.137951021472F,   24.729165942658F,
  25.441180498393F,   23.342321092299F,   18.849437945338F,   12.665460224658F,
   5.679729921072F,   -1.155244085373F,   -6.953793513501F,  -11.016144814009F,
 -12.920317024892F,  -12.574382645271F,  -10.222043730018F,   -6.400885000073F,
  -1.859182307116F,    2.557119682814F,    6.031477997894F,    7.900062101100F,
   7.753903063472F,    5.505276445024F,    1.408536622829F,   -3.968174416859F,
  -9.817166842776F,  -15.201825590172F,  -19.188897295390F,  -20.984515811290F,
 -20.055231027335F,  -16.217025999697F,   -9.679350067243F,   -1.037039643960F,
   8.790122772285F,   18.663457763845F,   27.364099064706F,   33.746865066307F,
  36.889500445338F,   36.217787513351F,   31.589882272990F,   23.328292229701F,
  12.194530794382F,   -0.691202059516F,  -13.975904577896F,  -26.229934592640F,
 -36.114224971212F,  -42.537858094769F,  -44.786484713218F,  -42.605750449484F,
 -36.229587007395F,  -26.350191103488F,  -14.033845342574F,   -0.593481500937F,
  12.565820148428F,   24.109033890925F,   32.921078538547F,   38.226295192105F,
  39.663618935850F,   37.309465922365F,   31.647185606619F,   23.488761612335F,
  13.860387477011F,    3.867829285796F,   -5.440418984739F,  -13.194514697004F,
 -18.794174603063F,  -21.958702035703F,  -22.731590508477F,  -21.441478990451F,
 -18.627134710957F,  -14.938824012733F,  -11.031279984848F,   -7.464127770149F,
  -4.624032545761F,   -2.679251047675F,   -1.572228294493F,   -1.050117499799F,
  -0.727438612220F,   -0.170334820777F,    1.011290087010F,    3.078619635632F,
   6.099585030450F,    9.916087104325F,   14.148849005050F,   18.240351817810F,
  21.530551388028F,   23.355007598243F,   23.151410004725F,   20.558794936933F,
  15.494287585912F,    8.194927387889F,   -0.783301077223F,  -10.611314507822F,
 -20.273498742850F,  -28.685019177865F,  -34.825301602028F,  -37.870404129850F,
 -37.306586673063F,  -33.009362366329F,  -25.276460259110F,  -14.808917856183F,
  -2.641203693433F,    9.972037971812F,   21.699220301693F,   31.287486718708F,
  37.711388217455F,   40.295751501615F,   38.797009334826F,   33.432429723980F,
  24.853263630217F,   14.064976975477F,    2.304507218564F,   -9.110002585808F,
 -18.938016016408F,  -26.163918912177F,  -30.114329788303F,  -30.530832908747F,
 -27.589384410598F,  -21.864584936484F,  -14.244162252746F,   -5.805423859467F,
   2.329719857474F,    9.141929503935F,   13.844490913175F,   15.979396972630F,
  15.467278775518F,   12.605262779125F,    8.013827747508F,    2.540540161564F,
  -2.865746111375F,   -7.292786924134F,   -9.996009656627F,  -10.504863754137F,
  -8.690037108783F,   -4.782493080899F,    0.658143186668F,    6.821436788058F,
  12.759552536663F,   17.520727629830F,   20.284597264822F,   20.480903832287F,
  17.875346943083F,   12.610739576728F,    5.197629131250F,   -3.544685668711F,
 -12.589168998358F,  -20.830897059839F,  -27.228690977503F,  -30.939906056819F,
 -31.430655876784F,  -28.547008296796F,  -22.537858120239F,  -14.026560701453F,
  -3.935146181712F,    6.628874009857F,   16.508269913764F,   24.636758925198F,
  30.166442510829F,   32.565820122958F,   31.676250565342F,   27.720357254402F,
  21.262293713181F,   13.126130017862F,    4.284038068142F,   -4.270275621441F,
 -11.645806329367F,  -17.159770905092F,  -20.410931582815F,  -21.311937107964F,
 -20.077709929424F,  -17.173035102085F,  -13.228097178157F,   -8.934998327853F,
  -4.940692135146F,   -1.751965524588F,    0.333913933707F,    1.263198717662F,
   1.219905771107F,    0.581783387786F,   -0.154871129033F,   -0.469799989009F,
   0.081886038935F,    1.781112690262F,    4.681024894873F,    8.578506761424F,
  13.026538610364F,   17.386956260807F,   20.917198915373F,   22.879453862594F,
}; 

// End of File