//#############################################################################
//! \file   golden.c
//! \brief  Ouput Vector (512) 
//! \author Vishal Coelho 
//! \date   21-Apr-2017
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

const float64_t test_golden[1026] = {
 122.875213675214L,  -61.650359056423L,    0.077516838645L,    0.030200458389L, 
   0.015059460219L,    0.010533261503L,    0.001420745861L,    0.004321252348L, 
   0.001665828039L,   -0.000205474225L,   -0.001559444501L,   -0.004978809199L, 
  -0.006965472949L,   -0.009974022278L,   -0.012129149506L,   -0.018060018110L, 
  -0.028579635974L,   -0.045845682637L,   -0.088760685430L,   -0.229814080231L, 
  -1.735608449194L,    5.298796974318L,   -5.464155410881L,   -8.064614410296L, 
  33.190551575942L,  -28.271399524897L,    4.190435911166L,    0.726077797401L, 
   0.254544863346L,    0.118601155842L,    0.060737424452L,    0.032906322558L, 
   0.013868053211L,    0.000093586930L,   -0.021358811607L,   -0.052767732062L, 
  -0.136345334044L,   -0.453770258129L,   -4.081966504555L,   15.783274134147L, 
 -13.564126342059L,    2.027082011125L,    0.347907169283L,    0.124806967588L, 
   0.059048580380L,    0.031282073531L,    0.018798229075L,    0.013783511042L, 
   0.013214983020L,    0.007228601029L,    0.007771175716L,    0.006165423233L, 
   0.004504396603L,    0.004533588993L,    0.001545959655L,    0.002828971027L, 
   0.000909313324L,    0.005224719722L,    0.001548907394L,    0.002576134081L, 
   0.002349621758L,    0.001009160728L,   -0.000450909332L,   -0.000793311628L, 
   0.000964529296L,   -0.001667308104L,    0.002292785879L,    0.000126041240L, 
  -0.000348779903L,   -0.000081065302L,   -0.000507550455L,    0.000989758903L, 
  -0.000742507951L,    0.002090524623L,    0.000198398482L,    0.001157812805L, 
  -0.002113590044L,   -0.000809723605L,    0.001799752322L,   -0.000984898278L, 
   0.001134141674L,    0.002095952140L,   -0.002246025088L,    0.000866899517L, 
   0.001777919050L,   -0.001485963520L,   -0.000536747249L,    0.001541570397L, 
  -0.001698836175L,    0.000844707274L,    0.000537289743L,   -0.000070289328L, 
  -0.000911892107L,   -0.000069254253L,   -0.001710600729L,    0.002512154965L, 
   0.000708765683L,   -0.000281962327L,    0.000763605090L,    0.000018825483L, 
   0.000877272639L,    0.000224047408L,   -0.000578714010L,    0.001027858088L, 
  -0.002255685838L,    0.000698260398L,    0.001219203459L,    0.001714214886L, 
  -0.000549598349L,    0.001215883802L,   -0.000172286397L,    0.001391686882L, 
  -0.002996491603L,    0.002849168488L,   -0.001274046111L,    0.000320554997L, 
   0.000602736516L,    0.000880488833L,    0.000698602828L,   -0.000532044834L, 
  -0.000001659129L,   -0.000536072414L,   -0.002481146647L,    0.000430961543L, 
  -0.001161583580L,    0.002094168225L,   -0.001694086571L,    0.001558532063L, 
  -0.000732600733L,   -0.000679679888L,    0.000296108672L,   -0.001185989286L, 
   0.002176600842L,    0.000606321012L,    0.003159241387L,   -0.000030115475L, 
   0.003102921251L,   -0.000928901003L,   -0.000113238572L,    0.000233047840L, 
  -0.000858859992L,    0.000334733939L,   -0.000322482941L,    0.001912350142L, 
   0.002024241362L,   -0.000541418082L,    0.000345165826L,   -0.000614524779L, 
  -0.000485066878L,    0.000467133851L,    0.000741291488L,   -0.000976368298L, 
  -0.001060689161L,   -0.001716531341L,   -0.000682582070L,   -0.000388243467L, 
   0.001007275965L,   -0.000411425129L,   -0.001569950934L,    0.001633525221L, 
   0.001496225098L,   -0.001781648176L,   -0.002572325358L,    0.001139798745L, 
   0.000133850285L,    0.000936627055L,    0.000567883563L,    0.000840254981L, 
   0.000646572937L,    0.000273144338L,   -0.000852823430L,    0.003561095150L, 
  -0.001485873585L,    0.001922155524L,   -0.001451207518L,   -0.000390069579L, 
   0.000621228415L,   -0.000240780551L,    0.001680352017L,   -0.000370828984L, 
   0.001246917324L,   -0.002186801759L,   -0.000481584606L,    0.001237988243L, 
  -0.001278825497L,   -0.000793256949L,   -0.000372593366L,   -0.000273146789L, 
  -0.000824494078L,    0.000906022426L,    0.000581612441L,   -0.001013962242L, 
  -0.001452929785L,    0.000012353327L,   -0.002432202049L,    0.001538089558L, 
  -0.001559588156L,    0.001498458832L,   -0.002920844227L,    0.000346634615L, 
   0.001440781228L,   -0.000296303110L,    0.000979389220L,   -0.000907748826L, 
   0.000417023346L,    0.000407930243L,   -0.000001392424L,    0.001295710504L, 
   0.000699127292L,   -0.000994270041L,   -0.000807635033L,   -0.000907049796L, 
   0.002061438130L,   -0.000720645587L,   -0.000121840381L,    0.001406492486L, 
  -0.001673134429L,   -0.001931954688L,    0.001166030193L,   -0.000544507140L, 
   0.001839271730L,   -0.001015165067L,   -0.002292623692L,   -0.000262120043L, 
  -0.003374631295L,   -0.002050803814L,    0.002558237723L,    0.000560207766L, 
   0.001127414104L,   -0.001071670009L,    0.000981462045L,    0.000678743262L, 
  -0.000845410631L,    0.000630110146L,    0.000107215599L,   -0.000059109657L, 
  -0.000805285688L,    0.000595706120L,    0.000483121930L,   -0.000008846300L, 
  -0.001746409815L,   -0.001271402889L,    0.000707694733L,    0.001966098790L, 
   0.000529401162L,    0.001285575213L,   -0.001939790574L,    0.000712154373L, 
   0.001251324034L,    0.000107617562L,    0.001391364202L,   -0.000498385660L, 
   0.001281485710L,   -0.001472419144L,   -0.000384303806L,    0.001164246423L, 
  -0.000976800977L,    0.000297950476L,   -0.001255863350L,    0.000158662480L, 
   0.000701889363L,   -0.001098038317L,   -0.001502651337L,   -0.001413045658L, 
   0.001325906301L,    0.000927776087L,    0.000158020477L,   -0.001777168262L, 
   0.000561914434L,    0.001317370912L,    0.000070005320L,    0.000852165634L, 
  -0.003256808954L,    0.001604649531L,   -0.000009781940L,    0.000605401819L, 
  -0.001762735757L,   -0.000787811420L,   -0.000530981903L,   -0.001381142588L, 
  -0.000582745735L,    0.000091687693L,    0.000850907193L,   -0.000374231936L, 
   0.001727334290L,   -0.002831252723L,    0.000721139933L,    0.001518780087L, 
   0.001824420535L,   -0.002664113503L,    0.001763453006L,   -0.001041748908L, 
  -0.001635277660L,   -0.000629430682L,    0.001179028447L,   -0.002664118437L, 
   0.000935997213L,   -0.001427985867L,   -0.001482717622L,    0.001237556771L, 
  -0.001306027155L,   -0.000175433306L,    0.002620313367L,   -0.002321230353L, 
   0.000306509237L,    0.000770993879L,   -0.000112147990L,    0.000859665420L, 
   0.000058645932L,   -0.001593399318L,    0.000038835840L,   -0.001961032836L, 
  -0.001144836536L,   -0.001210061943L,    0.002738527465L,    0.000671611201L, 
   0.001113237006L,   -0.001143612815L,   -0.000747709391L,   -0.000376038237L, 
   0.001494827923L,   -0.002412958719L,    0.000037302662L,   -0.000133756983L, 
  -0.001157774123L,    0.002147400359L,    0.000552586062L,    0.001685069047L, 
  -0.000622716314L,   -0.000007225335L,   -0.001351646544L,    0.000679766388L, 
   0.000888270303L,   -0.001692802530L,   -0.000127935460L,   -0.000810153256L, 
   0.000840222752L,   -0.001483194419L,    0.001903640444L,    0.000483137620L, 
   0.003646677332L,    0.001278594785L,   -0.000775770057L,   -0.000952657890L, 
  -0.000180870335L,    0.002004838915L,   -0.002021809601L,    0.001307090705L, 
  -0.001015321731L,    0.000910249846L,    0.000653600964L,   -0.000850999900L, 
  -0.000148793410L,    0.000930277256L,   -0.001609979181L,   -0.000439054569L, 
  -0.003419407042L,   -0.000183802729L,    0.000966447753L,    0.001545902471L, 
  -0.000288983518L,    0.001552603714L,   -0.001498447849L,    0.000013247958L, 
   0.000126248186L,   -0.000620633709L,    0.000555545571L,    0.001687492107L, 
  -0.001909086679L,   -0.000057689862L,    0.002845850516L,   -0.002727060561L, 
  -0.000200409499L,   -0.000176444731L,   -0.000871034038L,   -0.000672814807L, 
   0.000119265103L,   -0.000029681855L,    0.000945172438L,    0.000062750110L, 
  -0.001277196677L,    0.000772670235L,   -0.000497466254L,   -0.000676603824L, 
   0.000244200244L,    0.000298689102L,   -0.000143071964L,    0.000080362905L, 
   0.001472589267L,    0.000655356277L,    0.000568957441L,   -0.002101007363L, 
   0.000754656779L,    0.002070143185L,    0.000021737172L,    0.001442499951L, 
  -0.000538872665L,    0.000901056315L,    0.000775738206L,   -0.002045453308L, 
   0.000365898959L,    0.000283583073L,   -0.001708372699L,    0.001044260364L, 
  -0.000449720302L,    0.001253421002L,   -0.000727255838L,    0.000372020197L, 
   0.000839080297L,    0.000703825469L,    0.000554578389L,    0.001003522281L, 
  -0.001464688301L,    0.000856998607L,   -0.000714875100L,   -0.000019548883L, 
   0.000709501736L,    0.000168645876L,   -0.000149006485L,   -0.000191840540L, 
   0.000669484843L,    0.001428334735L,    0.000429413377L,   -0.000041379314L, 
  -0.002352740936L,    0.000333088365L,   -0.000098247895L,   -0.000708102891L, 
  -0.000487570797L,    0.002966668092L,   -0.000618725739L,    0.001688949678L, 
   0.001780975540L,    0.000409594427L,   -0.002244011153L,    0.001315406163L, 
  -0.000119109070L,   -0.000464246927L,   -0.001387313171L,    0.002624744001L, 
  -0.000997833973L,    0.000901248515L,   -0.001741362459L,   -0.001297846025L, 
  -0.000205120603L,    0.002320293299L,    0.000213138081L,   -0.001852043777L, 
  -0.000458774031L,   -0.001198575715L,    0.002564197091L,   -0.000706800768L, 
  -0.003867619495L,    0.002168769089L,   -0.001199438746L,    0.000544733199L, 
   0.001050007328L,   -0.002256446640L,    0.000387166766L,   -0.001284883710L, 
  -0.000447404947L,    0.000201311540L,   -0.003137261628L,   -0.002818034739L, 
  -0.003971927963L,   -0.004692074842L,   -0.007526080087L,   -0.009110181317L, 
  -0.021492516295L,   -0.044141710400L,   -0.124513778883L,   -0.745154460571L, 
   5.086852079180L,   -6.028193673061L,    1.589089151064L,    0.178732873510L, 
   0.057017324350L,    0.022691347674L,    0.009916251344L,    0.002056829770L, 
  -0.003178090179L,   -0.010649712710L,   -0.021699587765L,   -0.041574377039L, 
  -0.094030349219L,   -0.272377503330L,   -1.598564711800L,   10.967307822433L, 
 -13.134142671696L,    3.152224905657L,    2.970294314769L,   -3.123656226010L, 
   1.000152940976L,    0.125508384054L,    0.051178354446L,    0.025408374630L, 
   0.015288608186L,    0.010377511027L,    0.007631832260L,    0.003363300070L, 
   0.004952471284L,    0.003742371640L,   -0.000776839108L,    0.002838575249L, 
   0.001047136446L,   -0.000702956773L,    0.001117608352L,   -0.000106609391L, 
   0.000682945049L,    0.001517463644L,   -0.000134086856L,   -0.377594210724L, 
 122.875213675214L,   61.651515384246L,    0.077516954615L,    0.030238557882L, 
   0.015074938011L,    0.010533800997L,    0.001807641345L,    0.004378055514L, 
   0.001967607124L,    0.002846002301L,    0.001742224483L,    0.006228473853L, 
   0.008546624200L,    0.010525821002L,    0.014330426769L,    0.020829234005L, 
   0.032411990569L,    0.052415762113L,    0.102458202414L,    0.261852756221L, 
   2.003158155078L,    6.150973710993L,    6.219295994774L,    8.658783254164L, 
  35.694795385822L,   30.324146681619L,    4.484993005948L,    0.775485958737L, 
   0.271357317996L,    0.125676819633L,    0.064497339776L,    0.034586737995L, 
   0.014227549229L,    0.002058957799L,    0.023548479228L,    0.057439801586L, 
   0.147787094808L,    0.487701637516L,    4.380371545239L,   16.895291099995L, 
  14.486600274005L,    2.159702907794L,    0.369517360309L,    0.132383041798L, 
   0.062838388757L,    0.032581644035L,    0.020248834480L,    0.014560245293L, 
   0.013798985033L,    0.007758478757L,    0.008380547866L,    0.006168708939L, 
   0.004526561603L,    0.004712149755L,    0.001593703033L,    0.003618650095L, 
   0.001389016238L,    0.005253040113L,    0.001959022057L,    0.003367495533L, 
   0.004525395338L,    0.001232060348L,    0.002603541040L,    0.001437333323L, 
   0.001068077888L,    0.002491983641L,    0.002302671260L,    0.002323714137L, 
   0.000404625608L,    0.001300375287L,    0.001813822119L,    0.001338608073L, 
   0.001243780806L,    0.003355528911L,    0.001401427769L,    0.001247419617L, 
   0.002116943515L,    0.001544650669L,    0.002876576867L,    0.001066673433L, 
   0.002111433449L,    0.002691758977L,    0.002329688871L,    0.003090733625L, 
   0.001843562158L,    0.001646055068L,    0.000545664969L,    0.001577145252L, 
   0.002901970755L,    0.000845720182L,    0.000687805289L,    0.001430063182L, 
   0.001131263528L,    0.000203958193L,    0.001717078271L,    0.002517809365L, 
   0.001002866645L,    0.000282639192L,    0.001046011062L,    0.000857205350L, 
   0.001707313417L,    0.001028228675L,    0.000801540451L,    0.001245737749L, 
   0.002406693654L,    0.000791180517L,    0.001419633096L,    0.002123581145L, 
   0.000710145545L,    0.001602764214L,    0.001717038113L,    0.001420285794L, 
   0.003018748743L,    0.003507369429L,    0.001491631073L,    0.000956377535L, 
   0.000808501736L,    0.001689990146L,    0.000698940925L,    0.002137420060L, 
   0.000754658603L,    0.002168318604L,    0.002545545374L,    0.000784359421L, 
   0.001875578727L,    0.002095709606L,    0.001700117318L,    0.001586895513L, 
   0.000772228977L,    0.000959039877L,    0.000578924019L,    0.001415482207L, 
   0.002523652626L,    0.000609559469L,    0.003297598684L,    0.000042284209L, 
   0.003105212466L,    0.001146968542L,    0.000878363973L,    0.000292308123L, 
   0.000881932228L,    0.002747527273L,    0.002864063618L,    0.001913220109L, 
   0.002782474625L,    0.001772219837L,    0.000654041535L,    0.000873399625L, 
   0.000501226975L,    0.000467321670L,    0.001671783188L,    0.001834086516L, 
   0.001099351158L,    0.002310042055L,    0.001183190408L,    0.000429553761L, 
   0.003564680826L,    0.000601697225L,    0.002248728285L,    0.001879845850L, 
   0.001503605342L,    0.001974454622L,    0.002654063294L,    0.001458662388L, 
   0.001024106497L,    0.001608028716L,    0.002100049000L,    0.002173800245L, 
   0.000671394550L,    0.000991042323L,    0.001152877697L,    0.003783675897L, 
   0.003937775498L,    0.001981944454L,    0.002393710551L,    0.001533629669L, 
   0.001044939719L,    0.000845176651L,    0.001685215233L,    0.001732943894L, 
   0.001530956219L,    0.002290018400L,    0.001434877037L,    0.001238009328L, 
   0.001422381896L,    0.001862448463L,    0.000666466183L,    0.002164702629L, 
   0.001421348446L,    0.000915842545L,    0.000582807446L,    0.002617343923L, 
   0.002084590002L,    0.000376241093L,    0.002544538492L,    0.001916655879L, 
   0.001916145049L,    0.001642084187L,    0.004003856101L,    0.001258731688L, 
   0.001840244886L,    0.001983291536L,    0.000980158899L,    0.001833829140L, 
   0.000421126841L,    0.000951541759L,    0.000112156633L,    0.001507745759L, 
   0.000763365498L,    0.002525209549L,    0.002741954866L,    0.000923859393L, 
   0.002440334833L,    0.001432088273L,    0.001487715236L,    0.002004336486L, 
   0.001917151429L,    0.003290892882L,    0.001658232339L,    0.000832268592L, 
   0.002461108190L,    0.001454579286L,    0.002892384812L,    0.002676977339L, 
   0.003836228182L,    0.002551957922L,    0.002657935863L,    0.002886143573L, 
   0.002062703641L,    0.001135132657L,    0.001298965279L,    0.000684908058L, 
   0.001026796829L,    0.001518088813L,    0.000541698224L,    0.000790025813L, 
   0.001937968625L,    0.000849339239L,    0.000483220949L,    0.001604673915L, 
   0.003695504269L,    0.001530572303L,    0.000711148775L,    0.002366645426L, 
   0.000772019056L,    0.002193406178L,    0.001946216314L,    0.001169586388L, 
   0.001823139971L,    0.001417137810L,    0.002047890472L,    0.001205850908L, 
   0.001461114063L,    0.001480942916L,    0.001313347695L,    0.001201767123L, 
   0.000976800977L,    0.000000000000L,   -3.135467961129L,   -0.001729775421L, 
   0.050204156152L,    0.045318851491L,   -0.010120868153L,    0.666538227732L, 
  -0.161261731992L,    0.561182575359L,    1.643056686368L,   -2.679425199434L, 
   2.497030001593L,    2.523520317381L,    2.816360765700L,    2.579968690164L, 
   2.620049686077L,    2.650379373871L,    2.635518958290L,    2.618565697944L, 
   2.641725438052L,    2.618815765281L,   -0.532665294805L,    2.643679250848L, 
   2.768980683699L,   -0.376810701825L,    2.771535054637L,   -0.364439049042L, 
  -0.358889394015L,   -0.353857169945L,   -0.337155265790L,   -0.343135646719L, 
  -0.312998871675L,   -0.225276412809L,    1.525327116513L,    2.706935524814L, 
   2.735475036906L,    2.745510059266L,    2.766369728319L,    2.770348651641L, 
  -0.364837255256L,    2.782802289233L,   -0.352266883165L,   -0.343689674655L, 
  -0.339949319216L,   -0.349074683215L,   -0.283388772865L,   -0.380817650553L, 
  -0.328107916719L,   -0.291972743881L,   -0.371721622453L,   -0.383696160820L, 
   0.032640102144L,   -0.099001556159L,   -0.276171918381L,    0.245390686918L, 
  -0.673288635203L,    0.857082666548L,    0.103885413391L,   -0.658920923948L, 
   0.699754997217L,   -1.024872258295L,   -0.610984128416L,    1.744864828546L, 
  -2.155476792385L,   -0.443974884422L,   -2.303751231221L,    0.092693911734L, 
   1.516528409514L,   -2.609962413680L,   -1.633176704073L,   -1.854406817299L, 
   0.738626354714L,   -2.210523431588L,    0.898212752448L,   -1.428750304796L, 
  -0.381341356690L,   -3.085298282564L,    2.122585229014L,   -0.894822043687L, 
   2.747476404463L,    1.003750010746L,    0.678276631238L,   -2.872784074189L, 
   1.286498625071L,   -0.267656513620L,   -2.696898527413L,   -2.960553662756L, 
   0.212799433612L,   -2.196179231592L,   -0.048947444687L,    0.674265911096L, 
   1.619967343293L,    2.508299237556L,   -1.917236055558L,   -3.054704278861L, 
   0.067031379812L,    0.785917143618L,   -3.072371882453L,   -0.752450576162L, 
   1.548833098567L,   -1.031150458274L,    1.351137685403L,    2.377488177175L, 
   0.600417337429L,    2.785468276748L,    0.489527571201L,   -0.537842586017L, 
   0.631355227582L,   -2.455809820930L,    0.709608879010L,   -1.671304760066L, 
   0.201017253711L,    3.020085067262L,   -0.622646804903L,    2.594671025722L, 
   1.229004074621L,   -0.729514454991L,    1.022771475973L,    0.031105171562L, 
   1.822360469236L,    1.572994844264L,   -1.820616316561L,    2.916177513504L, 
   0.989097733321L,    2.238672755060L,    0.038355797393L,   -3.057338835541L, 
   0.189351765855L,    2.819842099189L,   -2.358462495668L,   -1.033888839743L, 
   2.564164730508L,   -0.530645899981L,    0.103126069781L,    0.290701600232L, 
  -2.363445852692L,    0.038417482516L,   -2.514735103023L,   -1.700076013196L, 
  -0.648041129477L,   -2.912350965115L,   -1.448661931174L,    1.683631900229L, 
  -0.030157851581L,   -0.756129870054L,    1.881262732514L,    1.014855146321L, 
  -2.351248662718L,    2.886972036702L,    0.028352490651L,   -1.111392693922L, 
   2.132165601189L,   -2.875599791017L,    2.408447977993L,    2.185724185238L, 
  -2.699433178701L,   -1.284322884918L,   -2.323719021707L,   -2.343607379491L, 
   0.517683961416L,   -0.099119981411L,   -2.695986365367L,    2.892768731865L, 
   0.673890219577L,   -1.439721751248L,    0.949033344952L,   -1.296972849275L, 
   1.173922175246L,   -0.272764750500L,   -1.291568784082L,   -2.403472068350L, 
   0.344710233774L,    1.957716782661L,    0.246250720823L,    2.222143806539L, 
  -1.827965712767L,    0.934138650799L,   -1.859685745012L,   -0.075989503160L, 
  -1.786451914770L,    0.618981848988L,    2.840212084845L,   -1.913067922891L, 
  -0.005836285213L,   -2.688444348401L,    2.010776533192L,    2.164045766795L, 
   1.697315722999L,   -2.189621733699L,   -0.146572260804L,    0.064048904485L, 
  -1.968607344980L,    2.341981884871L,   -1.537956885364L,   -2.843341807729L, 
  -0.639346212996L,    2.521663597404L,    0.421357122088L,    2.388398370907L, 
  -1.291807162731L,   -0.671436074494L,   -1.720757432288L,    0.039632358520L, 
  -2.088633292947L,    0.139713633834L,    1.127737983882L,   -1.583211636076L, 
   0.536761211329L,    0.413179797296L,   -1.975490479580L,    1.869777954209L, 
  -2.950540732551L,   -0.564725065661L,    2.098109267386L,   -1.652785804799L, 
  -0.792980852884L,    2.631540353416L,   -2.198219856289L,    0.790940933514L, 
  -2.283979536695L,   -0.726754539812L,   -2.343271071006L,    2.485925439633L, 
  -1.668869892072L,    2.645973214957L,    2.504148977290L,    0.274759823022L, 
  -1.375453830472L,    0.992532276898L,   -2.805626740202L,    0.714269156513L, 
   0.134271713304L,   -2.538080695552L,   -1.142778740463L,   -1.371555779777L, 
  -1.645686216735L,   -1.999322638698L,    0.793470284693L,   -0.020244587140L, 
   1.576309188040L,   -2.063008789238L,    2.551109122800L,    0.098599451907L, 
   0.590336487229L,    0.815182084265L,   -0.944548139397L,    3.060309490968L, 
   0.916130486892L,    0.814329010788L,   -1.494783064817L,   -0.823833454453L, 
  -1.996878237568L,    0.501087450182L,    3.034250511903L,   -1.867755582724L, 
   0.250539823628L,    3.141592653590L, 
}; 



// End of File
