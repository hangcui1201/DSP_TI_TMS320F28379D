//#############################################################################
//! \file   input.c
//! \brief  FID Input Vectors (256) 
//! \author Vishal Coelho 
//! \date   11-Apr-2016
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

#include "fpu64/fid.h"
#include <stdint.h>

const int64_t test_dividend[256] = {
#if SIGNED_DIV_TRUNCATED == 1
    -4631064875744813056L,  -446676349577064448L, -1861733463268032512L,  1834311932127059968L, 
     5543666549106991104L, -7285195302707427328L,  5929561889541214208L,  6291932237388738560L, 
    -2683886073867945984L, -1289990726062698496L,  1332578374143600640L,  3704562412208627712L, 
     4472777552758904832L,  4757122927167594496L, -2045213323574214656L, -1304138965855240192L, 
     8418073106319290368L,  1346084136747288576L,  6451233231103848448L, -4125700711133130752L, 
     2256472422888192000L,  1629985381987790848L,  8549484174976378880L, -7638747007551959040L, 
        9202925738598400L,   398259236993800192L, -7560102870694365184L,  7464778986052722688L, 
     7090724373456273408L, -1125442002289022976L,  5196864940259706880L, -6484675754720303104L, 
     2210213746135486464L, -4415713723517368320L, -1002465959569940480L,  6345670949659258880L, 
    -5604030115016388608L, -3618298915094085632L,  -308160833646323712L, -2991839718549258240L, 
     5506091706812915712L,  8992558538631235584L, -6289462499341449216L, -4853711299447947264L, 
     3730607405153382400L, -2297142368142921728L,  8738313106106920960L,  8712499710376140800L, 
     2650761141567920128L,  6642651822558953472L, -1809931846326865920L,  2433693665730428928L, 
     8951036102472259584L,  1097164486415390720L,  7998359103970639872L,  4064614729476462592L, 
     -294437395399548928L,  2564670984978847744L,  7150638058600398848L, -5557326069739204608L, 
    -1930151565826875392L,  9079031844531478528L, -1801294731594119168L,  2930384850802446336L, 
     7403566110081329152L,  9138180850205028352L,  2825363847843389440L, -7223073003936825344L, 
    -8557185753302777856L,  2178398864046780416L,  1238594859924858880L,  8521743813633658880L, 
     4539844609510373376L,  2997892875689742336L,   430054818255241216L, -4429168740091465728L, 
     8522280781951662080L,   741633590741723136L, -8664986079180937216L,  3621362664512681984L, 
      363698919283279872L, -8134450483983171584L,  7194898573834536960L, -3132215776633663488L, 
    -4986132826301716480L, -7121390600422768640L, -3487860315072780288L, -5009539452253650944L, 
     2803852843580893184L, -8002933150504706048L, -4142559862691762176L, -4024706239777437696L, 
     7010985024218583040L, -1026923625750429696L,  4720782293237522432L,  1905481808407453696L, 
     5225334252091686912L, -7121722702999578624L,  8827945512466241536L,  6430473657517221888L, 
    -8289109056096534528L,  -623466122224836608L, -3216129417123031040L,  2401860617955743744L, 
    -4975102302258706432L,  1473617657455063040L,  1902898242740344832L,  1842444119142223872L, 
     -951337691896651776L, -8569924523434264576L,   254838726371602432L, -1702078091502747648L, 
    -7230274451228909568L,  -740164004019693568L,  -906053272547307520L,   943372686427678720L, 
     5633715274852593664L,  3705029889870395392L,  6866533075990024192L, -8260596758342801408L, 
    -5170967107583465472L,  -744473510804979712L,  8458451896989536256L,  5350392469967423488L, 
     -887756770440202240L, -3072707614250063872L, -8133255927889485824L,  4443918468477491200L, 
      125336846354518016L, -5535399106842451968L, -1343041929750151168L, -6111585637726775296L, 
     4642945702233452544L, -2428498331992774656L,  8150099796000755712L, -8906594569579466752L, 
     6070010135184451584L,  2335191317041350656L,   714747048853329920L,  2776375830995169280L, 
     4180576982002757632L, -7480365680319518720L,  6965009735077023744L, -8958437243133399040L, 
    -3794446799201796096L, -5904528318034509824L,  7863741265536884736L, -7965664967872747520L, 
     1495906015251517440L,  2529993501319208960L,  2790425413337100288L,  6726088948847368192L, 
    -8191230046606753792L,  5844946299036981248L,   533525334341003264L,  3585135052384153600L, 
    -5305193275140962304L,   798374091994908672L,  3735839630152953856L,  8419731464180797440L, 
    -1023016528354541568L, -7648060107403966464L, -8165633010012452864L,  2387939987294390272L, 
     5463539439687260160L,  3526857586345588736L, -2853566275931856896L,  8242312706997796864L, 
      372445632813877248L,  8371372733142061056L, -7865772178158977024L, -5404306675669254144L, 
     5073367697677150208L,  7640416736931250176L,  5212139486172764160L, -3771728355171833856L, 
    -6422312858631911424L,  6417816365672955904L,  5254639740116514816L, -4227412629571106816L, 
    -5021006267860164608L, -3301538909495992320L,  6079342262221369344L,  5943212488910288896L, 
     1303868453239486464L,  1325022916421206016L, -3947266163654189056L,  3673365804916267008L, 
     5464994459518812160L, -1077491732282212352L,  -992146846293051392L,  -633416764996354048L, 
    -4076007562664044544L,  3235103615676243968L,  7446296209463402496L,  7535972703538122752L, 
     4559978764182341632L, -4417782937428228096L,  3498200702538149888L, -6791525489761181696L, 
    -6945183790161297408L, -5701835960112713728L, -6535089294122311680L,  1568777805965012992L, 
    -7870087715125608448L,  5945869328897984512L,  4111834101152299008L,  7855694239040632832L, 
     -135793890199334912L,  2857085189095380992L,  7196507955104706560L,   710671412522672128L, 
    -4017605589970159616L,  8779866522289735680L, -8551439874203310080L, -3205221892174555136L, 
     8725561263328763904L, -2489708619285340160L, -3520568136596946944L, -6992932223153981440L, 
     7669523537066115072L, -6724240249082726400L, -3096878283997421568L,  7332209849546274816L, 
       -6478905164365824L,  2126692698848989184L,  1533532586419156992L,  3657139446103896064L, 
    -8682285816982730752L,   514344804801986560L, -8631732447229913088L,  6034710705040363520L, 
    -2951733497286840320L,  6395688326019575808L, -4684189708120080384L,  1503248276681019392L, 
     8073713375272304640L, -8341852084251930624L, -8227659972443463680L, -8843036438140293120L, 
     3347687706254596096L,  1819375189170325504L, -7119889173428205568L,  5464762167865993216L, 
     2173959619894681600L, -7928161129354088448L, -7945400560203311104L, -6714478546846425088L, 
     5329104238829058048L, -7518921330728470528L, -4835467307573547008L, -4728861348719398912L, 
    -7289743506696185856L,  6610441656047298560L,  3656140362183532544L,  4311781311550660608L, 
#elif SIGNED_DIV_MODULO == 1
     7312469749902364672L,  -327791163200958464L, -8963400685631318016L,  2266742265477951488L, 
    -4960415016922693632L,   506067290268241920L,  4150369129798934528L,  1981471608725659648L, 
     1630073210288316416L, -1227910470135715840L, -4719177160593547264L, -1310450172943964160L, 
    -9035631119522992128L,  2007401420251535360L,  8448151088785629184L, -7462694444210001920L, 
    -8566842022742052864L,  7124780250906853376L, -4668107874426654720L, -9058918275746744320L, 
     5809253651025117184L, -6631614888339283968L,  7007299006110068736L, -7463980873269925888L, 
    -2719786078519994368L,  1723305305196486656L,  1571323884793845760L,  3093182589739646976L, 
     2730618307402141696L, -1229123762197569536L, -6645277975691546624L,  4647279158231939072L, 
    -4763192935148517376L,  2775484615256551424L,  6592387838795714560L, -7667011550106591232L, 
     8708507946088871936L, -8643038657020370944L,  6187121903213912064L,  6192818215836012544L, 
    -8303663469377992704L,   846451151921913856L,  8175040613311514624L, -3293240590373339136L, 
     5653314696663384064L,  1870476887541282816L,  5342554598633412608L,  5518989772146313216L, 
    -8309063491160109056L, -3999279316366671872L,  2830778758322700288L,  -190825197256597504L, 
     8722584200819333120L,  4583829774246356992L,  1251448326897985536L, -3708456626349191168L, 
    -4498980450833262592L,  7130843383671881728L,  -981350869187835904L,  5828935992109572096L, 
    -7409368998672291840L,  6633328406839732224L, -8713706794295146496L,  7363136588101625856L, 
     7377507824197292032L,   444677390049875968L, -7006082389268465664L, -5943649927191580672L, 
     3802014047548313600L,  6112508622398642176L, -8580801463732359168L,  4756284702784614400L, 
     8432231360563439616L, -2898527396286935040L,  2550146327557818368L, -2896031607643248640L, 
    -5230179592196857856L,  5279469720567654400L,  4115283389149530112L, -4079702122447087616L, 
     1520591468941778944L, -1457186134401994752L, -7525004166159540224L, -8780146121679443968L, 
     -163331087380807680L, -4090251531959283712L, -2955958582550759424L, -3922707330449795072L, 
    -6070763794838671360L, -1858263860284182528L,  3645991005621985280L, -5466204927290843136L, 
     3068182165844787200L, -1050245277801048064L, -1230485164429893632L, -5990774891382112256L, 
    -5659418437361809408L,  2147594509608263680L, -4261002200301373440L,  1100863531366987776L, 
     8204816463974621184L,  3956303375730692096L,  3306019116031666176L,  8474076015803742208L, 
     5079021587418331136L,  1987211777581006848L,  8264184867040391168L, -8123178270435012608L, 
    -4266504174714679296L,  8977662217085988864L,  5021327922079326208L,  -454632921195972608L, 
     3337007804351574016L, -1532283317200027648L, -2210856981259575296L, -5289227751083937792L, 
    -2159412955196268544L, -8676098617505480704L,  -510586228626960384L, -3073731401482514432L, 
     8777787320221425664L,  1022752767459491840L,  6388174577988173824L, -1695929189799116800L, 
     -700641212312557568L,  6019296568985509888L,  9061099716165943296L,   441756157132750848L, 
     7847925422546341888L,  4409175107516592128L,  1243864989079283712L,  8647421575779495936L, 
     5985957749466888192L,  8478294743576135680L,  2699608415440236544L, -2221477093771849728L, 
     -432120866645540864L,  7598025957768972288L, -8949366760997019648L, -6332880739004930048L, 
     -524480105125998592L,   793056792105465856L, -8122266838938261504L,  2915144603811340288L, 
     7187502723515377664L, -7201007409713657856L, -1147883436522412032L, -4054039292115777536L, 
     8951214538498641920L,  2006244039985221632L, -4542525357923428352L, -6777062110278133760L, 
      830193710371389440L,  6046915230199926784L,  6216668432793235456L,  6149197179161337856L, 
    -5465485556570308608L,   819361930385123328L,  6916472426591848448L, -6991314414386120704L, 
     6573511427676655616L,  7374565908604514304L, -5204469853011693568L, -7803358558032474112L, 
     -475646335572578304L,  6180165918070820864L,  -564590234826788864L, -1590663862124988416L, 
       50659626399805440L, -6909413198124773376L, -6783138493978208256L,  6834064246371706880L, 
     1899095646817906688L, -4329418994026940416L,  6729419831739215872L, -8151441732735180800L, 
     -779303269630345216L,  4099044435413886976L, -2969941446157223936L, -1822172018844725248L, 
      497688583910078464L,  7272365329442930688L,  5134847824094951424L, -7943765623412916224L, 
    -4080705185672603648L, -2225233787115427840L,  6727021133835864064L, -1476470581235087360L, 
    -4798413674301960192L,  1801407871924996096L,  -379921695799461888L,  7351903767570249728L, 
     8018970058273374208L,  5863977067715524608L,  3853690468501876736L,  4486627615713609728L, 
     7373344061840891904L, -8019910053558218752L, -3026904627537717248L, -9143404061899325440L, 
     6052295623006097408L,   137158502203158528L, -2468867287807010816L, -5042607168531281920L, 
      642531632583733248L, -3883318793354465280L, -7962151589593257984L, -7655938439629393920L, 
    -7962731358053410816L, -1663591959841855488L, -6947387253933115392L, -1051158331607670784L, 
     7359139228613443584L, -2699883876432578560L, -7006477022209622016L,  1274873399031715840L, 
     6918132722529769472L, -2793298643720114176L, -8450065987989981184L, -6597667661773481984L, 
    -7810483614009614336L,  4436932435755702272L,  -801969849983510528L,  3103652060202426368L, 
     3675441364341876736L,  1316308234785650688L,  2373973143023974400L,  6968514446416160768L, 
     2994860990839961600L,  6925158820041392128L,  -599205240242345984L, -6616182493733761024L, 
    -7966513141684107264L,  3952074850186416128L, -3542032596684918784L,  3157417980802854912L, 
     2811668142535512064L,   572749974738071552L,  3968024363374555136L,    88740331741880320L, 
     -221372762374391808L,   -39876160090017792L,  8042329454569631744L, -2042392461724289024L, 
    -7062425145205884928L, -4788340267455637504L,  3410959677478756352L,  6258124613085145088L, 
     8672637720698173440L, -5254193257019592704L,  4802487082670333952L,  1551423747200749568L, 
    -1790227411300564992L,   185211541027442688L,   -80349975779264512L,  2792253075544127488L, 
#else //SIGNED_DIV_EUCLIDEAN == 1
    -1801074070366730240L,  7087816752213440512L,  3700038888417261568L, -4761615709746495488L, 
     4793051006786496512L, -3856739418392295424L, -4105530992144988160L, -9110702957570476032L, 
    -2311171514575013888L, -1163384853277546496L, -3610056060110663680L, -3857945956915277824L, 
    -4749735753152477184L,  8055390795265591296L,  6644337190384154624L, -1895803977713180672L, 
     -379650514704345088L,  1198966295111874560L,  -191488464363749376L, -4246225900811165696L, 
     9034111063243847680L, -5835153475273177088L,  6671389047209420800L, -8621407330740105216L, 
    -3099827406324332544L,  4588572170312318976L,  2663091106904674304L, -6101482652263503872L, 
     8341711761852790784L,   798194958289989632L, -4585611985526695936L,  1449403291149768704L, 
     7664190490983864320L,  7297467874234208256L,  -322695952173897728L, -1056260975847290880L, 
    -3472508219018690560L, -8203013041357428736L,  4681631892083396608L, -6789370646534135808L, 
    -2657767795951222784L, -1920841677462894592L,  7111611418483656704L, -8831571519184570368L, 
     6347168967923214336L, -3909406595117273088L, -4605360952029751296L,  -214357898737559552L, 
     4224970603406077952L, -5485764765707124736L, -5233780225934454784L,  8786820887610578944L, 
     1719896801586567168L, -3608117136643123200L,  8627595388840310784L,  7304354126941114368L, 
    -5718020698982952960L, -9190180369750259712L,  3906351945962360832L,  6783361964067450880L, 
    -7040976302177769472L, -8503525172165627904L,  1811369280042473472L,  1924244541812572160L, 
      303124470064783360L, -9084884874888046592L,  3485205405095118848L,  8227623716566960128L, 
     6890531414595764224L, -7133790307567169536L, -2682722143492560896L, -4760425240279609344L, 
     1112953125749700608L,  2079448103142250496L, -3674423726391089152L,  5499743899455111168L, 
     5453625425762678784L,  5185237090348017664L, -2746749109422039040L, -8221762645582264320L, 
     3849920656417337344L,  9092924803387377664L, -6226209896561074176L, -7128442851983302656L, 
     7616207315652902912L,  -338368988606504960L,  6489674360305842176L,  5716900610773288960L, 
    -5778266520386404352L, -4663339544409862144L, -8223764348501911552L,  2009984101103341568L, 
     5114035671021807616L,   204096420271091712L, -8711473257226702848L,  9046011786578151424L, 
       17338532931555328L, -3099099361767600128L, -6015794255565445120L,  2317582422120058880L, 
     1385993031799261184L,  4629863154582456320L, -6391450026873038848L, -2641809932354772992L, 
    -6567948465508450304L,  6467569686592489472L, -2990775407136126976L, -4146892763354304512L, 
    -9112489154129385472L,  5569292817876815872L,   -47808708139511808L,   698077208928061440L, 
     6842128415423070208L,  4110738279662088192L,  3100638163996903424L, -5924581518961780736L, 
      931474888282871808L,  8483197882434054144L,  1771287208660948992L,  5692124892998459392L, 
     8938044345597782016L,  7119049517955055616L, -5278775566938173440L, -8584560158566832128L, 
     -901606911278884864L, -8968907378359007232L,  -484951082634768384L,  8323117259476387840L, 
    -4631013065008834560L, -2095129530781335552L, -1264830957066962944L,  6103778301614944256L, 
     5988676796110667776L,  -867022569990588416L, -2203275977182550016L,  7855888018824783872L, 
     4442780757375520768L,  4383556488879900672L,  8244145056221114368L,   186306681330980864L, 
     5384220624233310208L,  -882243162477717504L,  6441579189026250752L, -2021194447273938944L, 
     4397270500940150784L,  8788740134317008896L,   429791764052598784L, -1292834492842936320L, 
    -5401979904580161536L, -3257669556557109248L, -7178177493369528320L, -2301968192367859712L, 
    -3137717764870799360L, -2912645479088293888L,  5849810291011094528L,   584490882635421696L, 
      389633023155810304L,  5060120998610468864L, -7004915482681315328L,  2314146846430568448L, 
    -2828832451016024064L, -3050733864164728832L,  1376432648348577792L,  6713464523400929280L, 
    -5560529862033225728L,  3181158792595095552L,  7412480461257228288L, -5549570477088663552L, 
    -3721000663697051648L,   -64189683897196544L,  7192463575143643136L,    26094577275289600L, 
    -4113711751467765760L,   626417831076677632L,  1369662516270862336L, -1608474885805617152L, 
    -8951030527499608064L,  3740350435997040640L,   124462976707072000L, -2190253895190886400L, 
    -8025596630723624960L, -2608739272580196352L, -4902199316914030592L, -5469384855249295360L, 
     5788211666185625600L, -1965784779092060160L, -8235084571267538944L, -2304891558021701632L, 
     5072747212584118272L, -6174169128658483200L,  7604096495982086144L, -3335064672971485184L, 
    -3140010895307945984L, -5455888899887726592L,  4929241854722181120L, -7932595266090452992L, 
     8301661063488253952L, -6304916624720820224L, -3939378448383465472L,  3451922888292352000L, 
    -6619617364159205376L,   222959348176261120L,  4082761184415975424L,  7910796464034732032L, 
     4281560319772616704L,  4608882495879038976L, -1709651562162577408L, -4805530020566341632L, 
      384623377672079360L, -5182108042581925888L,  6315942037154045952L,  3005581674454218752L, 
     5833511372542154752L,  5421084878088083456L,  -569908403289999360L, -3513643958649647104L, 
     3460226372425013248L,  8980838366591203328L,  4979401124731666432L,  6079693531136122880L, 
     3801592925752369152L,  1758646515699052544L,  4664704176027150336L,   -60464667161604096L, 
     6735508621514821632L, -7968482573324912640L,  8643147045884694528L, -7401639624262318080L, 
      866574291168983040L, -1789889256503279616L, -7248829684577507328L,  4135135976839585792L, 
     2097069178527133696L,  5219841828380878848L,  1228932834342467584L,  5742824845909170176L, 
     1416264644904441856L,  8190892900052750336L,  6852082727156568064L,   140235984352270336L, 
     5327847007543648256L,  -497496865155211264L,  6065320783017279488L, -3274636713392502784L, 
     8783353276922558464L, -4091284178640062464L, -7879880819797606400L,  4634257562795405312L, 
     6109351723118716928L,  7790762720257835008L, -3190838591172405248L,  5609087867323521024L, 
      705594109129650176L,  -677089971818582016L,  5916797789094238208L,  8336203664957988864L, 
#endif
}; 

const int32_t test_divisor[256] = {
#if SIGNED_DIV_TRUNCATED == 1
       646524108,     69881547,   -745657282,    694823474, 
     -1642543737,  -1512612688,  -2062595064,   1994117796, 
      2020236230,  -1615506821,   -139972870,    672995619, 
      -901146130,   1093226542,    249615129,   -310128441, 
      -999893911,   1089788139,   1711013287,    981159654, 
      -400161525,   1882552198,  -1050431083,    142435033, 
      1953157295,   -997516736,  -1073378382,   1836840346, 
     -1852924704,   -861568780,    393348283,  -1274320468, 
       583613895,   1281490499,      7305964,    647733191, 
      1271116983,  -1145150947,    433099942,  -1664461411, 
        67712964,   1451014718,   1807279751,     -7610986, 
      -955152957,    655068243,   1792284714,     42260131, 
      2036636914,  -1300177044,  -1669947779,   -870356683, 
      -444879003,   -340351749,   -809707174,    832550079, 
     -1752897129,   -420526180,   -879691749,   -831090006, 
     -1694102044,    402986492,   -933178212,  -1480811863, 
     -2144654692,   -929450607,    218231046,   1593012782, 
     -1966006568,   1738267673,  -1584954231,   1433354917, 
      1290501843,   1794781328,  -1557768925,     20325149, 
      -408200220,  -1401996891,    322911156,    456202546, 
     -1226446206,     85608383,   2101037053,    -43314048, 
       836974068,   -380440355,  -1998118687,   -889781692, 
      1294682405,   -659268931,  -1789644390,     47701499, 
      -571946159,   1028556641,    106258195,   1307907209, 
      1361123149,  -1333709831,  -1616224296,   1378669379, 
       592265768,  -2078249626,   1700612176,     66035367, 
       191220269,    457165803,   1118565038,   1526203193, 
      -503076184,  -1783918151,   1004478169,   -721600322, 
      1459213140,   -550944197,   1409673850,  -1389341910, 
     -1591200081,   1631587562,  -1958165233,    801956372, 
      1004046981,   -269842328,   -516087923,   2060113016, 
      -433819947,   -256895248,  -1473998899,   -747177061, 
      -798597936,   1694367449,  -1086522877,   -813127435, 
      -391405060,    893399987,  -1530564875,   1594816131, 
     -1790331791,   -164334733,  -2016963785,   1087488007, 
       859176723,  -1226160566,    772684740,    246070189, 
      1506154417,    251536871,   1725604747,   -345668830, 
      -609334085,    -47298253,  -1048134624,   1843267974, 
      -142778396,  -1056528237,   -295414520,    869859774, 
      -419490023,  -1366486457,   1530086892,    361641505, 
      -542974994,  -1195312820,  -1206911075,     95487615, 
      -285947269,   1036392737,  -1844904781,   1491785749, 
       772579724,  -1560569831,   1539325678,  -1289202618, 
       461021453,    184876797,  -1450304405,  -2123203905, 
      1166019828,   1137253894,   -339004551,  -1903472894, 
       368280540,  -1399492569,    981875310,    147278938, 
     -1060580809,   1791245094,   1108937060,   1662284337, 
     -1851997753,  -1359236050,   1018219297,    844883858, 
      1189675470,      8175123,   -319988688,    477759838, 
      1528028637,    733567997,    101327060,   -864081234, 
       876040521,   -508477416,    290704851,   1665850118, 
      1472955980,   1712826754,   1885503920,   1354783678, 
     -2141651818,  -2134209203,  -1771807943,  -1027668202, 
     -2049564103,   -326053221,   -682620761,    177613791, 
      1830382271,   -865438285,   -695420515,   1543955303, 
      -685140439,  -1554261034,     33496258,   1531827903, 
      -496869228,    840486130,    549344260,   -213081255, 
      -113310076,   1931474080,  -1788864351,   -945627588, 
      -227601874,    376115714,   1621926273,   -132712256, 
      -268785601,   1057356265,   -137823500,   1549741671, 
      -143829812,     -8141166,    -53984929,  -1161922765, 
     -1780039608,  -1858074520,   1668126362,  -1146036064, 
      1553041963,    909395299,   1601219612,   1881204294, 
     -1547522765,   -455695408,   2064001636,    621885606, 
#elif SIGNED_DIV_MODULO == 1
      1046709920,   -850603373,  -1762603317,   1400011086, 
      -474220186,   1182425340,  -1377099250,  -1677780829, 
      1740141811,   1616415253,   2146592718,   1564461963, 
     -1989095896,    191909627,   2137245227,     47279662, 
      1604222579,  -1845884721,   2093962929,   1815540355, 
       275998548,   -294368238,   -696452289,    947999903, 
     -2088833436,   -540907354,   1815419197,    199628568, 
      -112155041,    -14872105,   -820462959,   1936332570, 
      2070145377,     58253086,   2115657160,   -189649856, 
      -317651998,  -1231733146,  -1317483450,   1429168603, 
       973398930,    127756782,   1413391004,     51000294, 
       223174430,  -1231432004,    377186717,  -1534320264, 
     -1923185304,    787301501,    466259409,  -1204068592, 
      -402524583,    557950374,    237544439,  -1599535749, 
     -1420782347,  -2143191180,   -351489510,    -49453633, 
     -1460852195,    716566232,  -2070516249,  -1633481906, 
      1941863414,   2043777242,  -2014706715,    -26277281, 
      1557879677,  -1104338457,   1435679420,   1346863915, 
       553935263,  -2137870658,   -516581746,   1736909240, 
       774604503,   -520450691,    566741166,  -1102649005, 
       306716806,   2069009328,   1501872834,   -930100141, 
       783649701,   -609350500,   2091334552,  -1786765254, 
     -1072428052,   1337223530,  -1784889178,    134234752, 
      1291165863,   1025738013,  -1539045781,   -266742132, 
      -642611408,    -92352547,    375394745,  -1521252956, 
      1740881701,    602129711,  -1447663518,    283083832, 
      1853777192,   1215913331,    797520180,   -145087067, 
     -1029425941,    297504529,  -1079021787,   -776093755, 
      1764382152,   1654507477,   1265251942,   1828839195, 
     -1379371908,     75338657,    545483680,   1774604662, 
       704238287,   -475913202,   1030824712,   1364231334, 
       430977604,  -1782424036,   1814013801,  -1917282784, 
       116071287,  -1637012712,   -514781937,   1343605498, 
     -1099099674,   1651082748,    913311028,   -523348474, 
     -1078382060,  -1061485082,   1147802498,  -1933328482, 
       795808338,    516590600,   1059502417,   2049797400, 
      -498587667,  -1029909096,   1621219312,   1314672238, 
      -166983691,  -1756806173,    276032502,  -1342680267, 
       136105735,   -622627142,   -795498790,    973847193, 
        67743909,   1248310330,  -1269194699,    764959778, 
     -1922059959,   1293525446,    766946463,   1915593832, 
     -1754244419,   1754229443,     42747968,    493507054, 
      -789968177,  -1814677449,   1505875946,  -1526745309, 
      -556259285,    525667202,   2136969148,     74492485, 
      2106729626,  -1174525540,   -438064389,    844256092, 
     -1869853700,   1063698396,   -341877545,   1337098138, 
      -517091361,   -777097795,   2087573435,    937079852, 
      -372874636,  -1723870005,   1007423771,    589726026, 
     -1830335202,  -1629905015,   2068439966,    -13746379, 
     -2051217735,  -1916278906,  -1542435295,   1689959300, 
      -146801669,    261377699,    -23809807,  -1856347192, 
      1707878894,   -908105084,   -991936378,    404560902, 
      -103598803,   -565599785,    668344544,   1882056411, 
       517222234,   -932694705,  -1266236881,   -261417129, 
     -2030444846,   1615699419,    472842597,  -1273061033, 
        85542111,  -1916310031,   1555583171,   -245093743, 
       206197760,    287165085,    774790587,   -552424801, 
     -1811493901,   -187472215,  -1941996091,   1023305988, 
     -1984268296,   1950964517,   1040981249,   1878831583, 
        57397883,  -1112805415,  -1030941278,   1112285553, 
      2118891035,   -615444118,   1086016157,  -1674828952, 
       416806087,   -298091345,    990926338,  -1025740537, 
     -1740287756,   -210610210,    601615440,  -1580381246, 
      -202626121,    653692299,   1404447139,   -824303402, 
#else //SIGNED_DIV_EUCLIDEAN == 1
     -1819894082,    896235396,  -1138482255,   -434240273, 
      -995898003,   1428133819,   2127614314,    643175573, 
       875970739,   1856728096,    805961556,    293577845, 
      -511755965,    578014485,   -587428600,   -396771463, 
      -563930394,   -135726291,     14662345,   1763237758, 
     -1260869160,   -693191937,    318367122,    -56124746, 
     -1021261680,    341851320,   1624905093,  -1885704436, 
      -253933633,  -1785598288,    271603490,    168837656, 
      1151299914,  -1146368552,    375215826,   -176205901, 
      1550403830,    690785765,   -627584203,   -656329853, 
     -1057772696,   1943593584,   -866720149,  -1467134725, 
      -595724606,   1037789051,    884333809,    862825312, 
     -2120744095,   -539681533,   1724410553,   -780203023, 
       416967980,   -868463079,  -1610550969,   -479508752, 
      1364458470,   2066633912,   1554734503,  -1787475701, 
      -697021694,  -1133316601,   -782519901,   2080690057, 
       207235999,   1070526007,   1468242020,  -1430697815, 
      1731291048,  -1695978957,   1052666833,    985144971, 
       934024828,  -1574398569,   -232834475,     37740870, 
       130954801,   1544972937,    763322679,   1313565319, 
       134187102,   1958057716,  -1861108352,    178318570, 
      -937761684,    -82032431,    793983894,  -1253020679, 
       464547908,   -746567655,   1635726278,  -1574558146, 
     -1707645540,   1971892083,  -1490774560,  -1492337578, 
     -1479390370,  -1762785992,   -195745019,    725401476, 
      1422929888,   1246550420,    913586435,   -117692820, 
       895879292,   1967350490,     24805851,   -837290494, 
      1244729556,  -1132209370,  -1141160642,   -151614929, 
       512762406,    495336001,  -1620818001,  -1615794493, 
      -925741584,   1012464695,   -380928798,   1412966469, 
      1868800898,   -433505403,  -1923237478,    305741980, 
      1063734445,   -772048040,    -30346871,  -1195492317, 
      1886666358,    -75998204,    171781885,  -1198050634, 
     -1735403003,  -1889075152,   1372280168,   1165990440, 
     -1306976883,   1697019551,    791563100,    673650507, 
      2106171222,  -2002778498,   -325329727,    -43019798, 
       358648969,  -1789842805,    687858897,  -1922834435, 
       244085285,    910641510,    -51923470,    505090928, 
     -1229315956,    625599189,   -512637456,  -1702040391, 
      -526084021,  -1018505077,  -1111169833,    527954776, 
        98473988,   -372641042,  -1212073978,   1539976059, 
      1550518641,   -927974880,    495608512,   1200398269, 
      1953554326,   1802182219,   -494712787,  -1448937212, 
      1274537642,  -1658642584,  -1465338480,   -619213526, 
      1493611660,    355542533,    370130253,   1828960235, 
       322458704,  -2104631063,   1328765324,    467328345, 
       -86270086,   -994541947,  -1038968120,    -81563423, 
     -1171059410,  -1938738367,  -1420595590,  -1037465209, 
     -1297466423,    453948253,   1390296570,   1334081106, 
      1298098099,    893840145,   1543516130,   1207248811, 
     -1272182838,   2118893123,  -1745369361,    646901720, 
     -1223307506,  -1100056650,   -688535635,  -1297671367, 
        29349129,   1935990793,   -452658551,    362773726, 
       457573987,    921884094,   -422898141,   1540566208, 
      1805969246,   1077344826,   -920876614,   1274814101, 
     -1534309077,     19542919,    475401131,    875300313, 
      -501051181,    982187881,   1663375034,  -1907616935, 
     -1553848977,   1559352209,   -336096299,   -380902720, 
      1971997041,   1074795349,   2065866874,  -1144540900, 
     -1734192856,   -495715680,      1170597,    301746659, 
      2047117119,    -30686764,   -425704848,   2125966985, 
     -1026505738,    710064225,   1993966982,    735088103, 
      -862537424,    133687414,  -2141199358,   1648360384, 
      -410668206,   -853815505,   1935233198,   -169014724,
#endif
}; 

// End of File
