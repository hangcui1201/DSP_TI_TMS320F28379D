//#############################################################################
//! \file irfft2Input.c
//! \brief  Input Vector (512) 
//! \author Vishal Coelho 
//! \date   16-Feb-2016
//! 
//
//  Group:			C2000
//  Target Family:	$DEVICE$
//
//#############################################################################
// $TI Release: $
// $Release Date: $
// $Copyright: $
//#############################################################################


double test_input[1024] = {
	21.858737775684L,  0.000000000000L, 21.909375921700L, -0.210584628439L, 
	22.062720514873L, -0.423943878707L, 22.323164583161L, -0.642979398421L, 
	22.698385697177L, -0.870859326672L, 23.199931829216L, -1.111184776132L, 
	23.844158053075L, -1.368202757917L, 24.653663808371L, -1.647093920692L, 
	25.659484279685L, -1.954379286613L, 26.904470591843L, -2.298518292949L, 
	28.448625848847L, -2.690821870737L, 30.377805480741L, -3.146902116170L, 
	32.818500375520L, -3.689075704920L, 35.964279314030L, -4.350553647355L, 
	40.126219843271L, -5.183199831340L, 45.837272804812L, -6.273020342241L, 
	54.092716283310L, -7.774246932956L, 66.992709543322L, -9.994957838360L, 
	89.885041551455L, -13.658426370599L, 141.830068192088L, -21.013433145535L, 
	389.849805414439L, -46.766019119180L, -123.134952473924L, -85.272836862715L, 
	-192.894089295028L, 60.556435156808L, -95.623197173307L, 26.102582752775L, 
	-63.679056334115L, 16.982079780071L, -47.327610489152L, 12.702381986125L, 
	-37.346562291316L, 10.202691951139L, -30.617090444315L,  8.557153136069L, 
	-25.776003213356L,  7.388103901614L, -22.129846737399L,  6.512279674668L, 
	-19.287836936210L,  5.829878823225L, -17.012743585136L,  5.281862109678L, 
	-15.152138300315L,  4.831049904324L, -13.603584591156L,  4.452851554409L, 
	-12.295688055056L,  4.130346395809L, -11.177164337733L,  3.851505218497L, 
	-10.210225095609L,  3.607538601313L, -9.366413890154L,  3.391872484215L, 
	-8.623894313392L,  3.199489513122L, -7.965631678161L,  3.026492287975L, 
	-7.378142530432L,  2.869805892725L, -6.850615281049L,  2.726970475725L, 
	-6.374279479056L,  2.595993584973L, -5.941945373131L,  2.475243078947L, 
	-5.547662413861L,  2.363368161581L, -5.186462313516L,  2.259240273624L, 
	-4.854163187226L,  2.161908238189L, -4.547218461421L,  2.070563794178L, 
	-4.262599028753L,  1.984514804324L, -3.997700393093L,  1.903164204460L, 
	-3.750268806849L,  1.825993296777L, -3.518341988745L,  1.752548364100L, 
	-3.300201138612L,  1.682429847063L, -3.094331778724L,  1.615283515893L, 
	-2.899391543608L,  1.550793206192L, -2.714183476365L,  1.488674788925L, 
	-2.537633713780L,  1.428671119522L, -2.368772685480L,  1.370547766630L, 
	-2.206719135891L,  1.314089362878L, -2.050666417168L,  1.259096451609L, 
	-1.899870607527L,  1.205382727417L, -1.753640090625L,  1.152772586384L, 
	-1.611326293452L,  1.101098915484L, -1.472315326880L,  1.050201060601L, 
	-1.336020307516L,  0.999922919688L, -1.201874163936L,  0.950111112269L, 
	-1.069322746215L,  0.900613178958L, -0.937818065625L,  0.851275765112L, 
	-0.806811491854L,  0.801942741168L, -0.675746727874L,  0.752453208415L, 
	-0.544052366878L,  0.702639332730L, -0.411133810235L,  0.652323939523L, 
	-0.276364287913L,  0.601317790186L, -0.139074670202L,  0.549416442603L, 
	 0.001458312859L,  0.496396574150L,  0.146025926793L,  0.442011613100L, 
	 0.295503979924L,  0.385986480122L,  0.450872864179L,  0.328011181373L, 
	 0.613242145145L,  0.267732911800L,  0.783881110319L,  0.204746212322L, 
	 0.964257180832L,  0.138580563044L,  1.156084798142L,  0.068684565060L, 
	 1.361388415848L, -0.005594467727L,  1.582584718899L, -0.085037170305L, 
	 1.822591415125L, -0.170587427555L,  2.084973316972L, -0.263399796408L, 
	 2.374141655944L, -0.364904228642L,  2.695630850651L, -0.476895963691L, 
	 3.056490402360L, -0.601662832053L,  3.465852080863L, -0.742169516997L, 
	 3.935771375525L, -0.902330933148L,  4.482511639791L, -1.087429447307L, 
	 5.128568915187L, -1.304772762817L,  5.905989023618L, -1.564771689283L, 
	 6.862053837043L, -1.882787706445L,  8.069577857348L, -2.282478510219L, 
	 9.646857652858L, -2.802279963391L, 11.799787134648L, -3.509090165531L, 
	14.921402531542L, -4.530613564311L, 19.867094705327L, -6.144782846689L, 
	28.917851915537L, -9.092735475702L, 50.871685333568L, -16.233118113024L, 
	182.506435583460L, -59.010956966361L, -124.585485099971L, 40.762175084415L, 
	-47.792633454829L, 15.803617997169L, -30.059597308188L, 10.034792851560L, 
	-22.170287368077L,  7.464422960350L, -17.705196149647L,  6.006683942440L, 
	-14.830165124154L,  5.065621556988L, -12.822636222984L,  4.406462401662L, 
	-11.340336320957L,  3.917995101097L, -10.200181811894L,  3.540732052411L, 
	-9.295367795057L,  3.239970072204L, -8.559387886240L,  2.994099727593L, 
	-7.948664450726L,  2.788961559607L, -7.433450136313L,  2.614889814657L, 
	-6.992743420861L,  2.465060408180L, -6.611293647906L,  2.334517803903L, 
	-6.277757960444L,  2.219576167345L, -5.983524393479L,  2.117436967252L, 
	-5.721936176504L,  2.025936937894L, -5.487766253512L,  1.943377341821L, 
	-5.276852657649L,  1.868405497347L, -5.085840081615L,  1.799930810993L, 
	-4.911993228907L,  1.737064132843L, -4.753059713262L,  1.679073210976L, 
	-4.607167810091L,  1.625349469922L, -4.472749142947L,  1.575382890899L, 
	-4.348479487100L,  1.528742778592L, -4.233232922757L,  1.485062865414L, 
	-4.126045952353L,  1.444029653232L, -4.026089143316L,  1.405373200201L, 
	-3.932644516781L,  1.368859774518L, -3.845087367971L,  1.334285948055L, 
	-3.762871536648L,  1.301473810949L, -3.685517386953L,  1.270267066471L, 
	-3.612601932254L,  1.240527822820L, -3.543750671158L,  1.212133940859L, 
	-3.478630798270L,  1.184976828513L, -3.416945526875L,  1.158959596402L, 
	-3.358429316576L,  1.133995507502L, -3.302843841853L,  1.110006667503L, 
	-3.249974570612L,  1.086922913345L, -3.199627847624L,  1.064680865782L, 
	-3.151628397913L,  1.043223118366L, -3.105817181159L,  1.022497540472L, 
	-3.062049540768L,  1.002456676039L, -3.020193601420L,  0.983057223032L, 
	-2.980128876967L,  0.964259581238L, -2.941745057114L,  0.946027458130L, 
	-2.904940946632L,  0.928327524285L, -2.869623535126L,  0.911129111204L, 
	-2.835707178998L,  0.894403945578L, -2.803112880058L,  0.878125914940L, 
	-2.771767647731L,  0.862270860477L, -2.741603933721L,  0.846816393369L, 
	-2.712559129710L,  0.831741731599L, -2.684575120003L,  0.817027554616L, 
	-2.657597882232L,  0.802655873597L, -2.631577130176L,  0.788609915389L, 
	-2.606465993602L,  0.774874018476L, -2.582220730699L,  0.761433539526L, 
	-2.558800469305L,  0.748274769289L, -2.536166973595L,  0.735384856762L, 
	-2.514284433352L,  0.722751740692L, -2.493119273309L,  0.710364087581L, 
	-2.472639980344L,  0.698211235507L, -2.452816946621L,  0.686283143108L, 
	-2.433622326960L,  0.674570343189L, -2.415029908969L,  0.663063900474L, 
	-2.397014994600L,  0.651755373064L, -2.379554291984L,  0.640636777234L, 
	-2.362625816510L,  0.629700555229L, -2.346208800235L,  0.618939545764L, 
	-2.330283608819L,  0.608346956965L, -2.314831665253L,  0.597916341519L, 
	-2.299835379757L,  0.587641573823L, -2.285278085248L,  0.577516828939L, 
	-2.271143977886L,  0.567536563200L, -2.257418062226L,  0.557695496309L, 
	-2.244086100566L,  0.547988594800L, -2.231134566118L,  0.538411056737L, 
	-2.218550599678L,  0.528958297551L, -2.206321969474L,  0.519625936906L, 
	-2.194437033944L,  0.510409786516L, -2.182884707184L,  0.501305838822L, 
	-2.171654426841L,  0.492310256477L, -2.160736124269L,  0.483419362544L, 
	-2.150120196744L,  0.474629631380L, -2.139797481585L,  0.465937680122L, 
	-2.129759232028L,  0.457340260754L, -2.119997094716L,  0.448834252687L, 
	-2.110503088675L,  0.440416655829L, -2.101269585675L,  0.432084584097L, 
	-2.092289291860L,  0.423835259339L, -2.083555230553L,  0.415666005641L, 
	-2.075060726156L,  0.407574243988L, -2.066799389064L,  0.399557487244L, 
	-2.058765101514L,  0.391613335446L, -2.050952004302L,  0.383739471369L, 
	-2.043354484323L,  0.375933656360L, -2.035967162849L,  0.368193726413L, 
	-2.028784884524L,  0.360517588464L, -2.021802706999L,  0.352903216908L, 
	-2.015015891188L,  0.345348650301L, -2.008419892089L,  0.337851988252L, 
	-2.002010350134L,  0.330411388479L, -1.995783083039L,  0.323025064034L, 
	-1.989734078118L,  0.315691280663L, -1.983859485035L,  0.308408354318L, 
	-1.978155608957L,  0.301174648788L, -1.972618904096L,  0.293988573461L, 
	-1.967245967605L,  0.286848581195L, -1.962033533816L,  0.279753166291L, 
	-1.956978468785L,  0.272700862574L, -1.952077765148L,  0.265690241566L, 
	-1.947328537244L,  0.258719910740L, -1.942728016510L,  0.251788511864L, 
	-1.938273547122L,  0.244894719419L, -1.933962581868L,  0.238037239088L, 
	-1.929792678250L,  0.231214806320L, -1.925761494784L,  0.224426184945L, 
	-1.921866787505L,  0.217670165865L, -1.918106406661L,  0.210945565787L, 
	-1.914478293576L,  0.204251226020L, -1.910980477689L,  0.197586011317L, 
	-1.907611073746L,  0.190948808762L, -1.904368279147L,  0.184338526707L, 
	-1.901250371434L,  0.177754093744L, -1.898255705921L,  0.171194457721L, 
	-1.895382713444L,  0.164658584794L, -1.892629898247L,  0.158145458509L, 
	-1.889995835976L,  0.151654078921L, -1.887479171792L,  0.145183461745L, 
	-1.885078618590L,  0.138732637527L, -1.882792955321L,  0.132300650851L, 
	-1.880621025413L,  0.125886559566L, -1.878561735287L,  0.119489434038L, 
	-1.876614052968L,  0.113108356424L, -1.874777006775L,  0.106742419965L, 
	-1.873049684104L,  0.100390728298L, -1.871431230287L,  0.094052394792L, 
	-1.869920847537L,  0.087726541889L, -1.868517793957L,  0.081412300470L, 
	-1.867221382636L,  0.075108809232L, -1.866030980806L,  0.068815214077L, 
	-1.864946009077L,  0.062530667513L, -1.863965940735L,  0.056254328068L, 
	-1.863090301107L,  0.049985359710L, -1.862318666990L,  0.043722931281L, 
	-1.861650666147L,  0.037466215934L, -1.861085976861L,  0.031214390580L, 
	-1.860624327553L,  0.024966635340L, -1.860265496460L,  0.018722133002L, 
	-1.860009311370L,  0.012480068483L, -1.859855649421L,  0.006239628292L, 
	-1.859804436953L,  0.000000000000L, -1.859855649421L, -0.006239628292L, 
	-1.860009311370L, -0.012480068483L, -1.860265496460L, -0.018722133002L, 
	-1.860624327553L, -0.024966635340L, -1.861085976861L, -0.031214390580L, 
	-1.861650666147L, -0.037466215934L, -1.862318666990L, -0.043722931281L, 
	-1.863090301107L, -0.049985359710L, -1.863965940735L, -0.056254328068L, 
	-1.864946009077L, -0.062530667513L, -1.866030980806L, -0.068815214077L, 
	-1.867221382636L, -0.075108809232L, -1.868517793957L, -0.081412300470L, 
	-1.869920847537L, -0.087726541889L, -1.871431230287L, -0.094052394792L, 
	-1.873049684104L, -0.100390728298L, -1.874777006775L, -0.106742419965L, 
	-1.876614052968L, -0.113108356424L, -1.878561735287L, -0.119489434038L, 
	-1.880621025413L, -0.125886559566L, -1.882792955321L, -0.132300650851L, 
	-1.885078618590L, -0.138732637527L, -1.887479171792L, -0.145183461745L, 
	-1.889995835976L, -0.151654078921L, -1.892629898247L, -0.158145458509L, 
	-1.895382713444L, -0.164658584794L, -1.898255705921L, -0.171194457721L, 
	-1.901250371434L, -0.177754093744L, -1.904368279147L, -0.184338526707L, 
	-1.907611073746L, -0.190948808762L, -1.910980477689L, -0.197586011317L, 
	-1.914478293576L, -0.204251226020L, -1.918106406661L, -0.210945565787L, 
	-1.921866787505L, -0.217670165865L, -1.925761494784L, -0.224426184945L, 
	-1.929792678250L, -0.231214806320L, -1.933962581868L, -0.238037239088L, 
	-1.938273547122L, -0.244894719419L, -1.942728016510L, -0.251788511864L, 
	-1.947328537244L, -0.258719910740L, -1.952077765148L, -0.265690241566L, 
	-1.956978468785L, -0.272700862574L, -1.962033533816L, -0.279753166291L, 
	-1.967245967605L, -0.286848581195L, -1.972618904096L, -0.293988573461L, 
	-1.978155608957L, -0.301174648788L, -1.983859485035L, -0.308408354318L, 
	-1.989734078118L, -0.315691280663L, -1.995783083039L, -0.323025064034L, 
	-2.002010350134L, -0.330411388479L, -2.008419892089L, -0.337851988252L, 
	-2.015015891188L, -0.345348650301L, -2.021802706999L, -0.352903216908L, 
	-2.028784884524L, -0.360517588464L, -2.035967162849L, -0.368193726413L, 
	-2.043354484323L, -0.375933656360L, -2.050952004302L, -0.383739471369L, 
	-2.058765101514L, -0.391613335446L, -2.066799389064L, -0.399557487244L, 
	-2.075060726156L, -0.407574243988L, -2.083555230553L, -0.415666005641L, 
	-2.092289291860L, -0.423835259339L, -2.101269585675L, -0.432084584097L, 
	-2.110503088675L, -0.440416655829L, -2.119997094716L, -0.448834252687L, 
	-2.129759232028L, -0.457340260754L, -2.139797481585L, -0.465937680122L, 
	-2.150120196744L, -0.474629631380L, -2.160736124269L, -0.483419362544L, 
	-2.171654426841L, -0.492310256477L, -2.182884707184L, -0.501305838822L, 
	-2.194437033944L, -0.510409786516L, -2.206321969474L, -0.519625936906L, 
	-2.218550599678L, -0.528958297551L, -2.231134566118L, -0.538411056737L, 
	-2.244086100566L, -0.547988594800L, -2.257418062226L, -0.557695496309L, 
	-2.271143977886L, -0.567536563200L, -2.285278085248L, -0.577516828939L, 
	-2.299835379757L, -0.587641573823L, -2.314831665253L, -0.597916341519L, 
	-2.330283608819L, -0.608346956965L, -2.346208800235L, -0.618939545764L, 
	-2.362625816510L, -0.629700555229L, -2.379554291984L, -0.640636777234L, 
	-2.397014994600L, -0.651755373064L, -2.415029908969L, -0.663063900474L, 
	-2.433622326960L, -0.674570343189L, -2.452816946621L, -0.686283143108L, 
	-2.472639980344L, -0.698211235507L, -2.493119273309L, -0.710364087581L, 
	-2.514284433352L, -0.722751740692L, -2.536166973595L, -0.735384856762L, 
	-2.558800469305L, -0.748274769289L, -2.582220730699L, -0.761433539526L, 
	-2.606465993602L, -0.774874018476L, -2.631577130176L, -0.788609915389L, 
	-2.657597882232L, -0.802655873597L, -2.684575120003L, -0.817027554616L, 
	-2.712559129710L, -0.831741731599L, -2.741603933721L, -0.846816393369L, 
	-2.771767647731L, -0.862270860477L, -2.803112880058L, -0.878125914940L, 
	-2.835707178998L, -0.894403945578L, -2.869623535126L, -0.911129111204L, 
	-2.904940946632L, -0.928327524285L, -2.941745057114L, -0.946027458130L, 
	-2.980128876967L, -0.964259581238L, -3.020193601420L, -0.983057223032L, 
	-3.062049540768L, -1.002456676039L, -3.105817181159L, -1.022497540472L, 
	-3.151628397913L, -1.043223118366L, -3.199627847624L, -1.064680865782L, 
	-3.249974570612L, -1.086922913345L, -3.302843841853L, -1.110006667503L, 
	-3.358429316576L, -1.133995507502L, -3.416945526875L, -1.158959596402L, 
	-3.478630798270L, -1.184976828513L, -3.543750671158L, -1.212133940859L, 
	-3.612601932254L, -1.240527822820L, -3.685517386953L, -1.270267066471L, 
	-3.762871536648L, -1.301473810949L, -3.845087367971L, -1.334285948055L, 
	-3.932644516781L, -1.368859774518L, -4.026089143316L, -1.405373200201L, 
	-4.126045952353L, -1.444029653232L, -4.233232922757L, -1.485062865414L, 
	-4.348479487100L, -1.528742778592L, -4.472749142947L, -1.575382890899L, 
	-4.607167810091L, -1.625349469922L, -4.753059713262L, -1.679073210976L, 
	-4.911993228907L, -1.737064132843L, -5.085840081615L, -1.799930810993L, 
	-5.276852657649L, -1.868405497347L, -5.487766253512L, -1.943377341821L, 
	-5.721936176504L, -2.025936937894L, -5.983524393479L, -2.117436967252L, 
	-6.277757960444L, -2.219576167345L, -6.611293647906L, -2.334517803903L, 
	-6.992743420861L, -2.465060408180L, -7.433450136313L, -2.614889814657L, 
	-7.948664450726L, -2.788961559607L, -8.559387886240L, -2.994099727593L, 
	-9.295367795057L, -3.239970072204L, -10.200181811894L, -3.540732052411L, 
	-11.340336320957L, -3.917995101097L, -12.822636222984L, -4.406462401662L, 
	-14.830165124154L, -5.065621556988L, -17.705196149647L, -6.006683942440L, 
	-22.170287368077L, -7.464422960350L, -30.059597308188L, -10.034792851560L, 
	-47.792633454829L, -15.803617997169L, -124.585485099971L, -40.762175084415L, 
	182.506435583460L, 59.010956966361L, 50.871685333568L, 16.233118113024L, 
	28.917851915537L,  9.092735475702L, 19.867094705327L,  6.144782846689L, 
	14.921402531542L,  4.530613564311L, 11.799787134648L,  3.509090165531L, 
	 9.646857652858L,  2.802279963391L,  8.069577857348L,  2.282478510219L, 
	 6.862053837043L,  1.882787706445L,  5.905989023618L,  1.564771689283L, 
	 5.128568915187L,  1.304772762817L,  4.482511639791L,  1.087429447307L, 
	 3.935771375525L,  0.902330933148L,  3.465852080863L,  0.742169516997L, 
	 3.056490402360L,  0.601662832053L,  2.695630850651L,  0.476895963691L, 
	 2.374141655944L,  0.364904228642L,  2.084973316972L,  0.263399796408L, 
	 1.822591415125L,  0.170587427555L,  1.582584718899L,  0.085037170305L, 
	 1.361388415848L,  0.005594467727L,  1.156084798142L, -0.068684565060L, 
	 0.964257180832L, -0.138580563044L,  0.783881110319L, -0.204746212322L, 
	 0.613242145145L, -0.267732911800L,  0.450872864179L, -0.328011181373L, 
	 0.295503979924L, -0.385986480122L,  0.146025926793L, -0.442011613100L, 
	 0.001458312859L, -0.496396574150L, -0.139074670202L, -0.549416442603L, 
	-0.276364287913L, -0.601317790186L, -0.411133810235L, -0.652323939523L, 
	-0.544052366878L, -0.702639332730L, -0.675746727874L, -0.752453208415L, 
	-0.806811491854L, -0.801942741168L, -0.937818065625L, -0.851275765112L, 
	-1.069322746215L, -0.900613178958L, -1.201874163936L, -0.950111112269L, 
	-1.336020307516L, -0.999922919688L, -1.472315326880L, -1.050201060601L, 
	-1.611326293452L, -1.101098915484L, -1.753640090625L, -1.152772586384L, 
	-1.899870607527L, -1.205382727417L, -2.050666417168L, -1.259096451609L, 
	-2.206719135891L, -1.314089362878L, -2.368772685480L, -1.370547766630L, 
	-2.537633713780L, -1.428671119522L, -2.714183476365L, -1.488674788925L, 
	-2.899391543608L, -1.550793206192L, -3.094331778724L, -1.615283515893L, 
	-3.300201138612L, -1.682429847063L, -3.518341988745L, -1.752548364100L, 
	-3.750268806849L, -1.825993296777L, -3.997700393093L, -1.903164204460L, 
	-4.262599028753L, -1.984514804324L, -4.547218461421L, -2.070563794178L, 
	-4.854163187226L, -2.161908238189L, -5.186462313516L, -2.259240273624L, 
	-5.547662413861L, -2.363368161581L, -5.941945373131L, -2.475243078947L, 
	-6.374279479056L, -2.595993584973L, -6.850615281049L, -2.726970475725L, 
	-7.378142530432L, -2.869805892725L, -7.965631678161L, -3.026492287975L, 
	-8.623894313392L, -3.199489513122L, -9.366413890154L, -3.391872484215L, 
	-10.210225095609L, -3.607538601313L, -11.177164337733L, -3.851505218497L, 
	-12.295688055056L, -4.130346395809L, -13.603584591156L, -4.452851554409L, 
	-15.152138300315L, -4.831049904324L, -17.012743585136L, -5.281862109678L, 
	-19.287836936210L, -5.829878823225L, -22.129846737399L, -6.512279674668L, 
	-25.776003213356L, -7.388103901614L, -30.617090444315L, -8.557153136069L, 
	-37.346562291316L, -10.202691951139L, -47.327610489152L, -12.702381986125L, 
	-63.679056334115L, -16.982079780071L, -95.623197173307L, -26.102582752775L, 
	-192.894089295028L, -60.556435156808L, -123.134952473924L, 85.272836862715L, 
	389.849805414439L, 46.766019119180L, 141.830068192088L, 21.013433145535L, 
	89.885041551455L, 13.658426370599L, 66.992709543322L,  9.994957838360L, 
	54.092716283310L,  7.774246932956L, 45.837272804812L,  6.273020342241L, 
	40.126219843271L,  5.183199831340L, 35.964279314030L,  4.350553647355L, 
	32.818500375520L,  3.689075704920L, 30.377805480741L,  3.146902116170L, 
	28.448625848847L,  2.690821870737L, 26.904470591843L,  2.298518292949L, 
	25.659484279685L,  1.954379286613L, 24.653663808371L,  1.647093920692L, 
	23.844158053075L,  1.368202757917L, 23.199931829216L,  1.111184776132L, 
	22.698385697177L,  0.870859326672L, 22.323164583161L,  0.642979398421L, 
	22.062720514873L,  0.423943878707L, 21.909375921700L,  0.210584628439L, 
}; 


// End of File
