/*
 *  Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
 *  Copyright (C) 2006-2008 - INRIA - Bruno JOFRET
 *
 *  This file must be used under the terms of the CeCILL.
 *  This source file is licensed as described in the file COPYING, which
 *  you should have received as part of this distribution.  The terms
 *  are also available at
 *  http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
 *
 */

#include "testAcosh.h"
#include "isnan.h"

#ifdef _MSC_VER
#include <float.h>
#define isnan(x) _isnan((double)x)
#endif

#define IN {38.746443623676896095276f,39.8779044859111309052f,99.6399083640426397324f,\
93.207842670381069183350f,6.8147667217999696731567f,71.874653641134500503540f,\
65.928971720859408378601f,43.781969323754310607910f,95.70061699487268924713f,\
39.777786191552877426147f,54.149620747193694114685f,14.754852838814258575439f,\
91.972588421776890754700f,41.853474546223878860474f,90.448315022513270378113f,\
32.027477025985717773438f,57.482325518503785133362f,75.726259034126996994019f,\
32.547289272770285606384f,50.125551037490367889404f,26.862081931903958320618f,\
11.706684622913599014282f,36.675705714151263237000f,87.538864836096763610840f,\
52.483216533437371253967f,76.861125137656927108765f,82.899243896827101707458f,\
64.99033216387033462524f,56.250627012923359870911f,21.698794979602098464966f,\
93.22312804870307445526f,93.5097210109233856201f,97.608120972290635108948f,\
91.35094834491610527039f,26.843591919168829917908f,9.1870715841650962829590f,\
17.129724519327282905579f,73.117265943437814712524f,86.922781122848391532898f,\
1.4808017760515213012695f,65.071928361430764198303f,42.254429217427968978882f,\
23.262092983350157737732f,31.955500133335590362549f,74.261871399357914924622f,\
77.881882060319185256958f,65.248953877016901969910f,90.324406325817108154297f,\
86.69646182097494602203f,70.879780035465955734253f,69.452034076675772666931f,\
84.671579115092754364014f,93.227435695007443428040f,95.654127094894647598267f,\
16.239900095388293266296f,12.728751823306083679199f,95.707353064790368080139f,\
67.644099798053503036499f,39.798104530200362205505f,11.081875301897525787354f,\
50.97153154201805591583f,58.446559030562639236450f,25.919713405892252922058f,\
29.182348400354385375977f,6.0309174004942178726196f,90.43274922296404838562f,\
61.944271018728613853455f,25.037935934960842132568f,83.850894169881939888000f,\
82.732185069471597671509f,73.220202280208468437195f,29.458374157547950744629f,\
29.091028729453682899475f,70.458725746721029281616f,30.465652560815215110779f,\
75.730663724243640899658f,73.18075490184128284454f,69.053836632519960403442f,\
62.402765033766627311707f,41.599050164222717285156f,28.105994546785950660706f,\
5.6220385245978832244873f,58.040395518764853477478f,0.4246918484568595886230f,\
68.2817161548882722855f,89.133544359356164932251f,92.980264825746417045593f,\
28.40001545846462249756f,9.885430941358208656311f,41.369083430618047714233f,\
64.121548598632216453552f,64.692758955061435699463f,47.02662643976509571075f,\
60.481913108378648757935f,67.138904659077525138855f,71.394702047109603881836f,\
54.127137595787644386292f,39.052018057554960250854f,1.1089378502219915390015f,\
90.150084160268306732178f,13.887455360963940620422f,8.5074969567358493804932f,\
34.66010238043963909149f,42.338709905743598937988f,80.213972786441445351f,\
31.7881367169320583344f,18.021041667088866233826f,69.688742049038410186768f,\
35.482168616726994514465f,16.12617420032620429993f,75.34236568026244640350f,\
62.194181978702545166016f,51.510728383436799049377f,67.819245439022779464722f,\
61.666865786537528038025f,70.212037675082683563232f,13.621602999046444892883f,\
60.870522353798151016235f,18.923167092725634574890f,47.614179179072380065918f,\
17.161004850640892982483f,41.371036972850561141968f,15.31781828962266445160f,\
22.868881560862064361572f,95.856341393664479255676f,39.499193150550127029419f,\
2.500818995758891106f,44.927055388689041137695f,91.384086245670914649963f,\
11.012465786188840866089f,74.87958460114896297455f,0.7881646975874900817871f,\
23.523587780073285102844f,80.106287542730569839478f,65.456348611041903495789f,\
51.620832458138465881348f,70.271815219894051551819f,5.5151230655610561370850f,\
62.56400248967111110687f,84.313133545219898223877f,17.294042231515049934387f,\
41.730730701237916946411f,81.875373004004359245300f,25.327575206756591796875f,\
86.085468018427491188049f,17.212611716240644454956f,78.060937067493796348572f,\
13.735765032470226287842f,0.2187759149819612503052f,1.4656470157206058502197f,\
30.469974083825945854187f,80.307766422629356384277f,99.052629480138421058655f,\
82.85992136225104331970f,87.21015579067170619965f,29.531141556799411773682f,\
58.27610609121620655060f,29.06773509457707405090f,2.0005736034363508224f,\
71.4346818625926971436f,26.664068037644028663635f,51.992803346365690231323f,\
48.17320345900952816010f,0.0918259844183921813965f,38.418471114709973335266f,\
49.06664276495575904846f,44.197808159515261650085f,65.678765252232551574707f,\
10.470610717311501502991f,42.787145730108022689819f,75.105277216061949729919f,\
36.962236650288105010986f,84.119305433705449104309f,90.374342072755098342896f,\
44.184404192492365837097f,1.0920032858848571777344f,20.380018139258027076721f,\
85.418348293751478195190f,39.327101549133658409119f,97.573022358119487762451f,\
8.4199145901948213577271f,23.39450428262352943420f,48.397052986547350883484f,\
33.292300626635551452637f,96.453859517350792884827f,52.920697536319494247437f,\
7.9968032892793416976929f,75.475437380373477935791f,4.476350219920277596f,\
84.631874877959489822388f,20.008285669609904289246f,69.44785490632057189941f,\
28.204387659206986427307f,79.546741675585508346558f,20.281786611303687095642f,\
78.075716458261013031006f,93.606285052374005317688f,88.801648560911417007446f,\
33.848348213359713554382f,89.761531725525856018066f}

#define RESULT {4.3500195892822599574856f,4.378812333443298676627f,5.2946847693089331698957f,\
5.2279502699832844925254f,2.6068118507181217147206f,4.968022463585481496295f,\
4.8816676362403299549442f,4.4722388068202851840738f,5.2543446283333992141706f,\
4.3762977630646631155287f,4.6848128785767624293612f,3.3835688928264802122214f,\
5.2146082054939908445590f,4.4271792498758397726988f,5.1978952030053422461719f,\
4.159497560939560578674f,4.7445490293632399669832f,5.0202285648475850621253f,\
4.1756051841813626168687f,4.6075785448582253778227f,3.9835162329116351465075f,\
3.1514779837977200394050f,4.2950758361772223281605f,5.165197419194649697261f,\
4.653549840642725143880f,5.035105083560019956224f,5.1107367420045859418565f,\
4.8673265089936572636020f,4.7228853485288873059744f,3.7698725167565876326137f,\
5.2281142583800894740875f,5.2311839874435639430317f,5.2740816359097371091025f,\
5.2078258853539018957690f,3.982827186610214287299f,2.9079691610609703644741f,\
3.5331093207527803912171f,4.9851649496034715625115f,5.1581342419725935144470f,\
0.9450506373811344840163f,4.8685813827251553931319f,4.4367163112396088564537f,\
3.8395099847061766595857f,4.1572465837028591550961f,5.0006994941965512424531f,\
5.0482993082581542054754f,4.8712984679982609392823f,5.1965242406243383754827f,\
5.1555269912574592794385f,4.954082618091184997411f,4.9337317049920867972901f,\
5.1318923054243690273779f,5.228160467885317963521f,5.2538586990129676479455f,\
3.4796690893012534040452f,3.2354639460120244720542f,5.2544150166005954005755f,\
4.9073526741507107473694f,4.3768085901327413722584f,3.0964161555968114925008f,\
4.6243182142058252281913f,4.7611868033967539304285f,3.9477786701409951497510f,\
4.0664175090632737052943f,2.4831009250018341028010f,5.1977230816033159754852f,\
4.8193171469932529760172f,3.9131402651137854320496f,5.1221517738388655516246f,\
5.1087193584020944570057f,4.98657191625376672306f,4.0758371911626332106948f,\
4.0632814774108050315249f,4.9481239065017428302440f,4.1094776238806378643176f,\
5.0202867341820684998766f,4.9860329708595516606806f,4.9279811897230469952547f,\
4.8266925606060153697285f,4.421080015153528108840f,4.0288134359166507536543f,\
2.4118364183807097234080f,4.7542122019999739634954f,0,\
4.9167355873994562642793f,5.1832514554357551617159f,5.2255055264178071894321f,\
4.0392267678246307482937f,2.9816410740582028893186f,4.4155348942144980739499f,\
4.8538668500531736427206f,4.8627367182462748473881f,4.5437480774189333843083f,\
4.7954231948046981415246f,4.8998553915953095838631f,4.9613217960209823331752f,\
4.6843975172654603866818f,4.3578777660333960497496f,0.4626347638559775710121f,\
5.1945923008314265345575f,3.3228343258666956927527f,2.830622803369744922009f,\
4.238528249750794785200f,4.438709481897562980635f,5.077806047884725337838f,\
4.1519928438683244564800f,3.5839165427001460351164f,4.9371344840241793150426f,\
4.2619788264190443527468f,3.4726281293145686568380f,5.0151457380383783757338f,\
4.8233440014012511909414f,4.6348430510092004652734f,4.9099388325030934865367f,\
4.81482819845952114690f,4.9446162371720561168331f,3.3034540778469194677314f,\
4.8018287252966844746993f,3.6328352359975357721567f,4.556167488561304601546f,\
3.5349368514717505185274f,4.41558212917596915048f,3.4210967363570983224008f,\
3.8224459155669441301484f,5.2559705982049909067655f,4.3692671498839636967659f,\
1.5671566063449566819088f,4.4980634827120455909721f,5.2081885950679547292452f,\
3.0901072205487807309510f,5.0089838747007107144782f,0,\
3.850698741029123794988f,5.076462566530570263978f,4.8744723131002718474747f,\
4.6369786693462113902342f,4.9454673471881154256380f,2.3923187222394570738970f,\
4.8292733779221936885051f,5.127649658742538640865f,3.5426723072020398497273f,\
4.424241396092424949416f,5.0983081346685077406278f,3.9246509637740216724922f,\
5.1484540607983912963164f,3.537944651477085589164f,5.0505959169093319616195f,\
3.3118225003889145696689f,0,0.9310418690232507010762f,\
4.1096195393026562214800f,5.0789747485012091132717f,5.2887730188734272118722f,\
5.1102622536361952398920f,5.1614350980940946200803f,4.0783057415377843568649f,\
4.7582657239633334711471f,4.0624799671967695147146f,1.3172890037212539038336f,\
4.9618816771260449982606f,3.9761122565887623281f,4.64415999832871140285f,\
4.5678423566873336270078f,0,4.3415161209508754680542f,\
4.5862227542495350718355f,4.481694375737592217490f,4.8778648861550966131517f,\
3.0394313734202933474648f,4.4492483198356360674097f,5.0119936831694982259933f,\
4.3028609023006350042806f,5.1253479422290126876760f,5.1970769705972195140475f,\
4.4813909798397162376205f,0.4257373352329655857851f,3.7070996451820255046528f,\
5.1406738437618608728030f,4.3648993866947414232982f,5.2737219653314042489001f,\
2.820201721217977297584f,3.8451912168199942065883f,4.5724793527790357217100f,\
4.1982477070823893683382f,5.2621850617105074832125f,4.661852422144622920541f,\
2.7682565538529817494862f,5.0169105620070073570105f,2.1792385497944919414692f,\
5.131423242241443638534f,3.6886685835548016498819f,4.9336715234659216378077f,\
4.032310316197459165721f,5.0694524637856641646749f,3.7022621441401133424165f,\
5.0507852459760567143121f,5.2322161767096924123166f,5.1795206909289932539764f,\
4.2148191048546337356129f,5.19027265701442619417f}

#define CRIN {0.1483933464623987674713f,0.5565875237807631492615f,0.4628333351574838161469f,\
0.9158247429877519607544f,0.0444016349501907825470f,0.8175177471712231636047f,\
0.5320580708794295787811f,0.2989391684532165527344f,0.5029047676362097263336f,\
0.4266923693940043449402f,0.3965902938507497310638f,0.7440190296620130538940f,\
0.7921002809889614582062f,0.5715918401256203651428f,0.4155966262333095073700f,\
0.2953372262418270111084f,0.1075767637230455875397f,0.7572548976168036460876f,\
0.93660886352881789207f,0.7694978956133127212524f,0.0902581927366554737091f,\
0.4731486858800053596497f,0.4765542480163276195526f,0.6361737176775932312012f,\
0.5064576440490782260895f,0.9049607468768954277039f,0.6742701171897351741791f,\
0.3656400945037603378296f,0.6837903787381947040558f,0.4100628877058625221252f,\
0.3582529271952807903290f,0.7118562050163745880127f,0.7966963038779795169830f,\
0.9753969227895140647888f,0.5733916512690484523773f,0.8998429346829652786255f,\
0.5953218084760010242462f,0.3765322910621762275696f,0.9104355531744658946991f,\
0.1861076802015304565430f,0.6715109744109213352203f,0.2566455481573939323425f,\
0.9819463356398046016693f,0.7608660291880369186401f,0.8556561623699963092804f,\
0.8441717335954308509827f,0.3884846637956798076630f,0.4608103148639202117920f,\
0.8381579727865755558014f,0.5278776129707694053650f,0.0187810636125504970551f,\
0.2611750457435846328735f,0.6092445817776024341583f,0.0081067951396107673645f,\
0.0276411953382194042206f,0.0158492103219032287598f,0.8109004520811140537262f,\
0.2429467244073748588562f,0.3353355019353330135345f,0.4142854567617177963257f,\
0.5946544189937412738800f,0.9080675477162003517151f,0.992223232518881559372f,\
0.6239561475813388824463f,0.0789771513082087039948f,0.5889828568324446678162f,\
0.2523608407936990261078f,0.5871062893420457839966f,0.0000379872508347034454f,\
0.4244823055341839790344f,0.69984475849196314812f,0.4405533373355865478516f,\
0.6495711454190313816071f,0.4199861017987132072449f,0.2716385438106954097748f,\
0.0272838752716779708862f,0.6936013107188045978546f,0.1495713749900460243f,\
0.5206344048492610454559f,0.9685971699655055999756f,0.9657785953022539615631f,\
0.0654204180464148521423f,0.9626990980468690395355f,0.2655456010252237319946f,\
0.8290728745050728321075f,0.1334408046677708625793f,0.8514542016200721263885f,\
0.8984219655394554138184f,0.1995774977840483188629f,0.0138073815032839775085f,\
0.2245407640002667903900f,0.3930436577647924423218f,0.8261723746545612812042f,\
0.5051761353388428688049f,0.5651183272711932659149f,0.822583723813295364380f,\
0.9197964356280863285065f,0.4713199352845549583435f,0.9223483256064355373383f,\
0.2136987913399934768677f,0.7260794681496918201447f,0.9689361499622464179993f,\
0.8346118587069213390350f,0.8257038742303848266602f,0.1350833275355398654938f,\
0.7953761396929621696472f,0.8992118402384221553802f,0.2715440522879362106323f,\
0.9219025229103863239288f,0.1750466236844658851624f,0.3323095212690532207489f,\
0.9493130259215831756592f,0.7118741781450808048248f,0.8032329222187399864197f,\
0.3628453887067735195160f,0.7530685458332300186157f,0.2641473677940666675568f,\
0.9660940738394856452942f,0.8041944387368857860565f,0.5316947177052497863770f,\
0.1673618280328810214996f,0.955579827539622783661f,0.6473058252595365047455f,\
0.2645611818879842758179f,0.5411860425956547260284f,0.4980195099487900733948f,\
0.0190768833272159099579f,0.4227291680872440338135f,0.8374647037126123905182f,\
0.4151327675208449363708f,0.3497115275822579860687f,0.4844544250518083572388f,\
0.3347255480475723743439f,0.2362121837213635444641f,0.0928130256943404674530f,\
0.0737370252609252929688f,0.4197955676354467868805f,0.9802277712151408195496f,\
0.8419611467979848384857f,0.6906680446118116378784f,0.2502765958197414875031f,\
0.8266033390536904335022f,0.1875236849300563335419f,0.5023231171071529388428f,\
0.8916302681900560855865f,0.8934147348627448081970f,0.1574523574672639369965f,\
0.1629528645426034927368f,0.5226223585195839405060f,0.8417599620297551155090f,\
0.5858130785636603832245f,0.1322202011942863464355f,0.8028764897026121616364f,\
0.5250511718913912773132f,0.2528006075881421566010f,0.4602345135062932968140f,\
0.996287219692021608353f,0.4019785309210419654846f,0.1399875725619494915009f,\
0.5081327147781848907471f,0.9440425024367868900299f,0.9318959629163146018982f,\
0.6445578685961663722992f,0.5729571748524904251099f,0.4810055238194763660431f,\
0.6713787661865353584290f,0.0962744313292205333710f,0.8855805248022079467773f,\
0.3892059125937521457672f,0.2907031057402491569519f,0.4209313853643834590912f,\
0.9504273366183042526245f,0.482190326321870088577f,0.2289973804727196693420f,\
0.2940405677072703838348f,0.6957426778972148895264f,0.9139824123121798038483f,\
0.2068154653534293174744f,0.6285024262033402919769f,0.4031575415283441543579f,\
0.3064021435566246509552f,0.3148818286135792732239f,0.7400112929753959178925f,\
0.8853011503815650939941f,0.788494529668241739273f,0.8977585239335894584656f,\
0.0339450328610837459564f,0.8802101369947195053101f,0.5418177028186619281769f,\
0.9511840576305985450745f,0.5574890668503940105438f,0.1312845982611179351807f,\
0.9453403786756098270416f,0.2518341308459639549255f,0.2607447705231606960297f,\
0.1215410251170396804810f,0.9136986923404037952423f,0.9382542567327618598938f,\
0.3105722474865615367889f,0.9309121072292327880859f}

#define CIIN {0.5225624092854559421539f,0.7617142526432871818542f,0.3009174778126180171967f,\
0.1853434126824140548706f,0.5148605112917721271515f,0.7257346073165535926819f,\
0.7033738414756953716278f,0.5664369426667690277100f,0.7816161573864519596100f,\
0.3330347230657935142517f,0.4017280167900025844574f,0.8503915611654520034790f,\
0.41114101978018879890f,0.1586530329659581184387f,0.6542402538470923900604f,\
0.9449902996420860290527f,0.400338994804769754410f,0.9679889930412173271179f,\
0.32740902295336127281f,0.8933845367282629013062f,0.6218692888505756855011f,\
0.0985169494524598121643f,0.7449700380675494670868f,0.3134250529110431671143f,\
0.1409188793040812015533f,0.3239218806847929954529f,0.9958796552382409572601f,\
0.2412899602204561233521f,0.4753343504853546619415f,0.9194070147350430488586f,\
0.0450326460413634777069f,0.8481595069169998168945f,0.8928631045855581760406f,\
0.1469233212992548942566f,0.4904643460176885128021f,0.9986877571791410446167f,\
0.3392539476044476032257f,0.8790708789601922035217f,0.3107871781103312969208f,\
0.1200211457908153533936f,0.0909670502878725528717f,0.5804221173748373985291f,\
0.446611551102250814438f,0.3501139078289270401001f,0.7262432840652763843536f,\
0.3650169344618916511536f,0.5597011330537497997284f,0.434090383350849151611f,\
0.5082829319871962070465f,0.3487796885892748832703f,0.8136124997399747371674f,\
0.337404197081923484802f,0.7742837746627628803253f,0.0156080657616257667542f,\
0.0195691580884158611298f,0.0445443131029605865479f,0.4240885511972010135651f,\
0.8158838218078017234802f,0.9913199446164071559906f,0.5120379645377397537231f,\
0.1021917951293289661407f,0.7161553995683789253235f,0.4527317988686263561249f,\
0.2445004582405090332031f,0.1668560453690588474274f,0.9187424210831522941589f,\
0.3418669118545949459076f,0.4624818544834852218628f,0.0400874321348965167999f,\
0.4700120547786355018616f,0.8552942494861781597137f,0.3308605216443538665771f,\
0.0322206378914415836334f,0.9760772576555609703064f,0.0763854510150849819183f,\
0.2165335658937692642212f,0.2348632332868874073029f,0.1446668924763798713684f,\
0.5313451024703681468964f,0.4441541358828544616699f,0.5759493880905210971832f,\
0.3719177199527621269226f,0.5167253850959241390228f,0.5186656024307012557983f,\
0.6306529571302235126495f,0.0928382659330964088440f,0.5421750987879931926727f,\
0.2833826132118701934814f,0.2819099412299692630768f,0.1141945635899901390076f,\
0.7321730605326592922211f,0.9823690224438905715942f,0.8243003231473267078400f,\
0.6485677706077694892883f,0.5304958778433501720428f,0.6958626955747604370117f,\
0.6050392785109579563141f,0.2683336613699793815613f,0.5511700971983373165131f,\
0.1174971889704465866089f,0.7958277617581188678741f,0.4983139941468834877014f,\
0.9196587274782359600067f,0.1420703046023845672607f,0.389312467072159051895f,\
0.2658497532829642295837f,0.9480321384035050868988f,0.2326095197349786758423f,\
0.0139051643200218677521f,0.9270462663844227790833f,0.4878733339719474315643f,\
0.0354842916131019592285f,0.6607114099897444248199f,0.0879401965066790580750f,\
0.8046676008962094783783f,0.212315237149596214294f,0.9163186331279575824738f,\
0.9393384093418717384338f,0.3174265320412814617157f,0.9574301876127719879150f,\
0.7951935962773859500885f,0.3240787154063582420349f,0.0472964248619973659515f,\
0.1696171183139085769653f,0.7654392314143478870392f,0.2554624872282147407532f,\
0.1189010548405349254608f,0.7469239532947540283203f,0.0616608508862555027008f,\
0.1056091515347361564636f,0.1581688239239156246185f,0.9732552450150251388550f,\
0.8786917333491146564484f,0.1824825564399361610413f,0.9303942839615046977997f,\
0.4655157290399074554443f,0.5399280847050249576569f,0.9143392136320471763611f,\
0.0622840351425111293793f,0.6500507537275552749634f,0.2340233740396797657013f,\
0.3603484155610203742981f,0.1917369994334876537323f,0.2371335849165916442871f,\
0.4136920445598661899567f,0.2661342276260256767273f,0.3891090690158307552338f,\
0.6622495856136083602905f,0.4503725995309650897980f,0.3829893553629517555237f,\
0.1937121297232806682587f,0.9629272706806659698486f,0.6385000632144510746002f,\
0.2695108866319060325623f,0.1092974594794213771820f,0.0598662365227937698364f,\
0.1431378168053925037384f,0.2944079088047146797180f,0.9022735017351806163788f,\
0.9111119657754898071289f,0.9847188093699514865875f,0.0592310009524226188660f,\
0.5464080139063298702240f,0.5080275069922208786011f,0.6546461437828838825226f,\
0.9597736010327935218811f,0.1577645908109843730927f,0.1818120293319225311279f,\
0.4555030376650393009186f,0.1048952480778098106384f,0.7636235631071031093597f,\
0.1893162522464990615845f,0.1596221593208611011505f,0.3115166993811726570129f,\
0.2491372707299888134003f,0.0469047501683235168457f,0.0797643386758863925934f,\
0.3945369226858019828796f,0.3254697113297879695892f,0.5811151321977376937866f,\
0.1456566532142460346222f,0.4704219633713364601135f,0.8631705637089908123016f,\
0.1648640967905521392822f,0.0801398889161646366119f,0.4932156866416335105896f,\
0.4345335862599313259125f,0.1079503614455461502075f,0.2686753761954605579376f,\
0.7417223947122693061829f,0.4086893904022872447968f,0.6706044673919677734375f,\
0.4159612008370459079742f,0.4766113189980387687683f,0.4431825890205800533295f,\
0.6688354592770338058472f,0.5834077899344265460968f,0.4861929873004555702209f,\
0.715783319901674985886f,0.1403244398534297943115f}

#define CRRESULT {0.5053397031743451783825f,0.7650083608446867078356f,0.3289296819323739295982f,\
0.3563456766158749622342f,0.4948207655225617118688f,0.8169593462846268527855f,\
0.7132198900639351579755f,0.5570137230416445373038f,0.7685376318852206178889f,\
0.3559803193123551312560f,0.4189790595413633300659f,0.8813522345691391368661f,\
0.5405451162482487470484f,0.1905551975849387180695f,0.6493731034151291048317f,\
0.8578709195697519218626f,0.3922142862720902067863f,0.9642946930057294530059f,\
0.5389615746319644795648f,0.9186094888728127960675f,0.5890418064066422765279f,\
0.1113977102429560134267f,0.7345860770241963155769f,0.3799876579856086289411f,\
0.1619970506356118999935f,0.51382943864194075001f,0.9605702232101991366875f,\
0.2552214504374311077051f,0.5588288246069162967800f,0.8545155572742579863643f,\
0.0482073009402987154304f,0.8701819105023789191478f,0.9267094766915666692597f,\
0.3583874762657675017152f,0.5394241582016752190043f,1.0267057888096897677599f,\
0.3962322220487046187110f,0.8200372580795054489045f,0.5035682683774097556650f,\
0.1218215489911998739014f,0.1217295472085216101465f,0.5645974853924803360528f,\
0.6787204142960019392916f,0.4641409785094591788912f,0.8320374579652175528466f,\
0.5202648072575078996849f,0.5635084163999081185992f,0.4608376215542885900867f,\
0.6521335567127740651117f,0.3901559225476997627702f,0.7433295520896158192770f,\
0.3414853587252406064145f,0.7876437052847802267053f,0.0156079448330699189357f,\
0.0195753850507095344957f,0.0445351746116087257588f,0.5619901990592348628439f,\
0.7563216032216260042986f,0.8953230010983072029163f,0.5250759023565449989945f,\
0.1262270783291525866332f,0.8463340938014771719367f,0.6903512283163251161966f,\
0.3002023271844543317322f,0.1665929038330317135674f,0.8881085995755062523216f,\
0.3450945758035259824936f,0.5168125326109850314893f,0.0400767031552608649081f,\
0.4881659313644853837033f,0.8717577944100705078512f,0.3559191435167290418207f,\
0.0423384874325624382951f,0.8962569818869624560520f,0.0792669980362326609402f,\
0.2149514867261388406661f,0.3084002596083564862184f,0.1457610223920582370738f,\
0.5638322964331675679617f,0.6681928703809085767773f,0.7715309042125101379739f,\
0.3644939000586688848671f,0.7241095709372292743566f,0.5109856481565466790329f,\
0.7492592023075983487246f,0.0935322123614654998836f,0.6873609600399674945947f,\
0.4653574362777189166174f,0.2834338708350941926639f,0.1139584955905696417311f,\
0.6886187601911135658384f,0.8966624572124947123442f,0.8901159605244814976288f,\
0.6621780758434868685569f,0.5739364819547106977282f,0.7967040377802739881119f,\
0.7702556784014074064970f,0.2963495189276508789966f,0.729639913718978516677f,\
0.1199467917211827494572f,0.8369585267706058928638f,0.7130151705637984838049f,\
0.9564173315765011063050f,0.2362741844905166255231f,0.3829952297292640861492f,\
0.3854654409071321952140f,0.9956878617898979877410f,0.2388852521695121466916f,\
0.0357548125472270175718f,0.8344528446849692748799f,0.4908081134490644426016f,\
0.1072298401775326898155f,0.7292248632489435333781f,0.1444440063075330404896f,\
0.7618560442692507983509f,0.3014073074948313002430f,0.8338433864005018181231f,\
1.013809216729007589564f,0.4488437286282063176657f,0.9028988520348978363828f,\
0.7342748763980897486192f,0.5492704923146081164020f,0.0619250478958671968233f,\
0.1747947745500638971894f,0.7643392221916658346714f,0.2869233753851287982428f,\
0.1186438529044472750540f,0.7261517086175122148717f,0.1110167797262640587697f,\
0.1156665104854840142590f,0.1677179018762894047168f,0.9049771869312485117476f,\
0.8140692858573190804350f,0.1865250841653489921601f,0.8328626043313867022277f,\
0.4511026850510220786994f,0.5511713324178673101272f,1.0040394102716723168101f,\
0.1134432764930088655131f,0.7136163206069113806862f,0.2389915016256592694699f,\
0.5061510239067475991348f,0.1938531425179492451161f,0.267912781705172242663f,\
0.594520593176991907214f,0.4421595740617755287971f,0.3838580911610497414799f,\
0.6265966551277006857390f,0.4892019455111443759776f,0.5371648663643865395656f,\
0.2336644699290637006150f,0.8580649693764487162539f,0.7447932141471096390006f,\
0.30664577808112553070f,0.1126796888171682081703f,0.0673404850217956818526f,\
0.3780061914448271664924f,0.3135468248495265064513f,0.8141814149801622768621f,\
0.8656800272972641208113f,1.0330415543607425199468f,0.1517147576472806791426f,\
0.6107832692276639052764f,0.5555300503019462432519f,0.6621194316643849164805f,\
0.9359383537376269046604f,0.1578266511911156633197f,0.3288869400610432980336f,\
0.4688911283964798393242f,0.1093517544178844447256f,0.7390278072154514710235f,\
0.3915656081630794482784f,0.1803516698292359499156f,0.3140185989593758941751f,\
0.2570435038916802361619f,0.0651252572213311814453f,0.1812803236410877871787f,\
0.3918987512324060840108f,0.3907169202420177067658f,0.5847178774812699098007f,\
0.1522469534945809221949f,0.4726351219523636792985f,0.8890284419930043480207f,\
0.3043305148205690535690f,0.1282404489119809976039f,0.6689999411776240689775f,\
0.4220981761434796641907f,0.2107039270298768085521f,0.3089304668962193911597f,\
0.8825265124364938262858f,0.4570764804119011315287f,0.6317437032300170507426f,\
0.6289949625530589782940f,0.4716158816756069738219f,0.4417016096894970100806f,\
0.6297964082740089564183f,0.7506329678118981441060f,0.6853639001045995771122f,\
0.6844909750084481325771f,0.3028385676048351293765f}

#define CIRESULT {1.4391441245686327210507f,1.130955515640670316913f,1.1164484564631134144719f,\
0.5343429881094952094145f,1.5313159234681512632648f,0.9218282568507811802760f,\
1.1368031918334591257036f,1.309961324172885133166f,1.1768313149474189938104f,\
1.1581725732800560724201f,1.198068547194847122128f,1.0167778558643913999759f,\
0.8107284978807606234952f,0.9747572654361357225028f,1.2226962809307837520834f,\
1.356863284326968122073f,1.4708283871101888173882f,1.0424189614104724110888f,\
0.6175483783889722522176f,1.012434899444895508580f,1.4941377955828787360559f,\
1.081247186686038253001f,1.189977918876721885155f,0.9361970185325101390106f,\
1.0473314366303878575337f,0.6478815708564551467674f,1.103880390282215628872f,\
1.208902068619972958174f,0.9405460211534443226711f,1.2708555309086870810376f,\
1.2048457921815343141247f,1.0386992340805454304586f,0.9940470159552662332558f,\
0.4129471251607437776165f,1.0483368304459323994138f,0.9626808065085141752348f,\
0.9866797451792658213421f,1.2893127532844186333705f,0.6333368050416610106623f,\
1.3849939050391590900091f,0.8412033774271403530065f,1.3484185557182311043789f,\
0.6561721869869621137639f,0.8152667302376208624537f,0.8942162872449925803409f,\
0.7354476761871528989190f,1.2302184692777484720239f,1.1419032200306009627866f,\
0.8136425490751511002685f,1.0585917357001826122342f,1.5562281161680697749716f,\
1.3215709464122720184776f,1.0936282246933759498830f,1.562690430228121041267f,\
1.5431569076078051061529f,1.5549621593607869662890f,0.7985043985204253180754f,\
1.3827954341839958640747f,1.3338048203354757603734f,1.1992311317991326546917f,\
0.9398015526727905299964f,0.8526323846859752420002f,0.6516084904889641871151f,\
0.9312161189612270240090f,1.4928235928235611407189f,1.1434135639085114544145f,\
1.3304436504678796016066f,1.0279557218905930326969f,1.5707583700301124274290f,\
1.18264027414866035315f,1.049240570305455033662f,1.1438977350867394200407f,\
0.8645410048697405036577f,1.272544314036070156604f,1.2965854453389789036066f,\
1.5441276936419627840991f,0.8474785980812834518261f,1.4222542688372477037717f,\
1.1067340541491283989473f,0.6658230283826037654293f,0.7440600810961385258580f,\
1.509454955782236762474f,0.7139904083352976993382f,1.3343109319103572119047f,\
0.8754276015708571945240f,1.4375430902494801266300f,0.8182153660902479197503f,\
0.6279916190243797213810f,1.3777792247900606525945f,1.5570776874524723254467f,\
1.3896877170114805277734f,1.292290381577097857502f,0.9513544490495031702437f,\
1.146595322853661613749f,1.0663673649265974496814f,0.9066444651210990857138f,\
0.7936124351430207113367f,1.1025133400691302654195f,0.7646931356316959416120f,\
1.3570006423237950254901f,1.0127507430242304042878f,0.6984070724030820853656f,\
0.9777377069899801931285f,0.6381815285628557044006f,1.4447151619316793702552f,\
0.7381184252357657626931f,0.9463444174447509515957f,1.3036540993301888313738f,\
0.3993509460349408124458f,1.4425649666003559357108f,1.2703537792660923866350f,\
0.3366052452908819825339f,0.9799364183556658058905f,0.6519110571169279833015f,\
1.288935099739083156578f,0.766834829952783847418f,1.3765235555687964641436f,\
0.9026821267000586512808f,0.7532458865053713870097f,1.1915253215495016370085f,\
1.4398661339551832583084f,0.5960292480319858698934f,0.8683763627836410536887f,\
1.307183356265154250409f,1.1437419441048803925298f,1.0721920855425228769064f,\
1.5518517938677236500666f,1.2329687641584510249260f,0.5874976025749066854686f,\
1.1457409989520814797004f,1.2187173974473419768572f,1.2272326680013900812583f,\
1.3202499364548996307889f,1.3364966855772182352524f,1.5028659601895917319325f,\
1.5039244799556488185743f,1.199080874147727016066f,0.8850027352965960103504f,\
0.5797999065603636204003f,0.9935513093218836244702f,1.3250345117052622079257f,\
0.7510747251416685088543f,1.3856864393507652977178f,1.0646397833458374204696f,\
0.7161423103150551527918f,0.6220745390646167383153f,1.4237426982899421545881f,\
1.4349026977530163762253f,1.0862935323189089054097f,0.7475103036060971595234f,\
0.9640755596017442918821f,1.4756182374730877349123f,0.8992686396344509169865f,\
1.0456992348735927311765f,1.316872193719026640224f,1.0937098269572853581622f,\
0.3787889502350130777053f,1.1777575502770252224849f,1.466927792635024818679f,\
1.198998549247170863907f,0.9317214709279717510526f,0.3994553068013038665818f,\
0.9996993047110468433303f,1.0533682169916682713762f,1.1680862767422879322510f,\
1.0968093743281353003027f,1.475564759332087749755f,0.5739680940616843640711f,\
1.2132055498728515630091f,1.277641763762892734846f,1.2372616699165408515881f,\
0.4908185034943345348424f,1.0764535824324550361553f,1.3508749145869605179371f,\
1.282220574891209663448f,0.8033914160655766245611f,0.4529330910646225394345f,\
1.3777085436870080137339f,0.9478851551815749010288f,1.2208388985822435923723f,\
1.263077873207383738929f,1.284175149159334061721f,1.023436357706823729430f,\
0.5626793926847969418148f,0.6728398111486185717567f,0.7545922256887819257187f,\
1.5396608871785673056110f,0.5335122401588628937574f,1.0275094129340511805992f,\
0.8338356239168208672297f,1.0426578447465559840168f,1.4617456602888381222982f,\
0.6682797094798482717692f,1.3426136823908161321839f,1.3312882615539098907220f,\
1.4697575902556172522395f,0.7877417380659905710161f,0.7165102522491650915981f,\
1.3183788402186256139004f,0.4738958779540429211430f}


void sacoshsTest(void) {
  float In[]=IN;
  float Res[]=RESULT;
  float out;
  int i = 0;

  for (i=0;i<200;i++){
	if (In[i]<1) assert(1);
	else {
		out = sacoshs(In[i]);
		assert ( ( fabs(out-Res[i]) / fabs(out) ) <1e-6);
	}
  }
}

void cacoshsTest(void) {
  float InR[]=CRIN;
  float InI[]=CIIN;
  float ResR[]=CRRESULT;
  float ResI[]=CIRESULT;
  int i=0;
  floatComplex in,out;

  for (i=0;i<200;i++){
	in=FloatComplex(InR[i],InI[i]);
	out=cacoshs(in);
	assert( ( fabs(creals(out)-ResR[i]) / fabs(creals(out)) ) <1e-6);
	assert( ( fabs(cimags(out)-ResI[i]) / fabs(cimags(out)) ) <1e-6);
  }
}

void sacoshaTest(void) {
  float In[]=IN;
  float Res[]=RESULT;
  float out[200],in[200];
  int i = 0;

  for (i=0;i<200;i++){
	in[i]=In[i];
  } 

  sacosha(in,200,out);
  for (i=0;i<200;i++){
	if (isnan(out[i])) assert(1);
	else{
		assert ( ( fabs(out[i]-Res[i]) / fabs(out[i]) ) <1e-6);
	}
  }
}

void cacoshaTest(void) {
  float InR[]=CRIN;
  float InI[]=CIIN;
  float ResR[]=CRRESULT;
  float ResI[]=CIRESULT;
  int i=0;
  floatComplex in[200],out[200];

  for (i=0;i<200;i++){
	in[i]=FloatComplex(InR[i],InI[i]);
  }
  cacosha(in,200,out);
  for (i=0;i<200;i++){
	assert( ( fabs(creals(out[i])-ResR[i]) / fabs(creals(out[i])) ) <1e-6);
	assert( ( fabs(cimags(out[i])-ResI[i]) / fabs(cimags(out[i])) ) <1e-6);
  }
}

int testAcosh(void) {
  printf("\n>>>> Float Hyperbolic ArcCosine Tests\n");
  sacoshsTest();
  cacoshsTest();
  sacoshaTest();
  cacoshaTest();
  return 0;
}

int main(void) {
  assert(testAcosh() == 0);
  return 0;
}
