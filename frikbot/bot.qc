
/*
======================================
FrikBot X (Version 0.10.2)
======================================

This program is in the Public Domain. My crack legal
team would like to add:

RYAN "FRIKAC" SMITH IS PROVIDING THIS SOFTWARE "AS IS"
AND MAKES NO WARRANTY, EXPRESS OR IMPLIED, AS TO THE
ACCURACY, CAPABILITY, EFFICIENCY, MERCHANTABILITY, OR
FUNCTIONING OF THIS SOFTWARE AND/OR DOCUMENTATION. IN
NO EVENT WILL RYAN "FRIKAC" SMITH BE LIABLE FOR ANY
GENERAL, CONSEQUENTIAL, INDIRECT, INCIDENTAL,
EXEMPLARY, OR SPECIAL DAMAGES, EVEN IF RYAN "FRIKAC"
SMITH HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH
DAMAGES, IRRESPECTIVE OF THE CAUSE OF SUCH DAMAGES. 

You accept this software on the condition that you
indemnify and hold harmless Ryan "FrikaC" Smith from
any and all liability or damages to third parties,
including attorney fees, court costs, and other
related costs and expenses, arising out of your use
of this software irrespective of the cause of said
liability. 

The export from the United States or the subsequent
reexport of this software is subject to compliance
with United States export control and munitions
control restrictions. You agree that in the event you
seek to export this software, you assume full
responsibility for obtaining all necessary export
licenses and approvals and for assuring compliance
with applicable reexport restrictions. 

Any reproduction of this software must contain
this notice in its entirety. 

======================================
These installation instructions only apply to Normal Quake (as does this
entire file). For QuakeWorld, please refer to bot_qw.qc

--------------------------------------
To install on a new mod, do all this:
--------------------------------------
Place all included bot*.qc files in the subdirectory "frikbot"
in your source folder, then...

* Add the following lines to progs.src right after the defs.qc line
frikbot/bot.qc
frikbot/bot_way.qc
frikbot/bot_fight.qc 
frikbot/bot_ai.qc
frikbot/bot_misc.qc
frikbot/bot_phys.qc
frikbot/bot_move.qc
frikbot/bot_ed.qc

--------------------------------------
* Comment out the following functions in defs.qc
sound, stuffcmd, sprint, aim, centerprint, setspawnparms
WriteByte, WriteChar, WriteShort, WriteLong, WriteCoord
WriteAngle, WriteString, WriteEntity
--------------------------------------
* Add this to worldspawn() in world.qc, right at the very top, before InitBodyQue();
BotInit();  // FrikBot
--------------------------------------
* add this line to StartFrame() in world.qc, at the very top
BotFrame(); // FrikBot
--------------------------------------
* Add these two lines to PlayerPreThink in client.qc at the very top
if (BotPreFrame()) // FrikBot
	return;
--------------------------------------
* Add this line to PlayerPostThink in client.qc at the very top
if (BotPostFrame()) // FrikBot
	return;
--------------------------------------
* Add the following line to the very top of Client Connect in client.qc
ClientInRankings(); // FrikBot
--------------------------------------
* Add these lines to the very top of ClientDisconnect in client.qc
ClientDisconnected(); // FrikBot
--------------------------------------

To install the waypoints:

add

waypoints/map_dm1.qc
waypoints/map_dm2.qc
waypoints/map_dm3.qc
waypoints/map_dm4.qc
waypoints/map_dm5.qc
waypoints/map_dm6.qc

To progs.src, immediately after defs.qc

To remove these waypoints:

Delete the code in bot_map_load, located below.
*/
void(vector org, vector bit1, float bit4, float flargs) make_way;
void() bot_map_load =
{
	// place your qc loaded waypoints here
	if(mapname =="de_dust")
	{
		make_way('-512.000000 -1728.000000 128.000000', '2 3 0', 0, 0);
		make_way('-673.000000 -1688.000000 128.000000', '1 0 0', 0, 0);
		make_way('-350.000000 -1686.000000 128.000000', '1 4 0', 0, 0);
		make_way('-217.000000 -1681.000000 128.000000', '3 5 0', 0, 0);
		make_way('-84.000000 -1673.000000 128.000000', '4 6 0', 0, 0);
		make_way('86.000000 -1655.000000 128.000000', '5 7 0', 0, 0);
		make_way('237.000000 -1650.000000 128.000000', '6 8 9', 18, 0);
		make_way('366.000000 -1684.000000 128.000000', '7 9 0', 0, 0);
		make_way('551.000000 -1683.000000 128.000000', '8 10 7', 0, 0);
		make_way('573.000000 -1513.000000 128.000000', '9 11 0', 0, 0);
		make_way('526.000000 -1385.000000 128.000000', '10 12 17', 0, 0);
		make_way('444.000000 -1273.000000 128.000000', '11 13 0', 0, 0);
		make_way('387.000000 -1150.000000 128.000000', '12 14 0', 0, 0);
		make_way('461.000000 -1020.000000 128.000000', '13 15 0', 0, 0);
		make_way('577.000000 -944.000000 128.000000', '14 16 0', 0, 0);
		make_way('592.000000 -1073.000000 128.000000', '15 17 0', 0, 0);
		make_way('-512.000000 -1728.000000 128.000000', '2 3 0', 0, 0);
		make_way('-673.000000 -1688.000000 128.000000', '1 0 0', 0, 0);
		make_way('-350.000000 -1686.000000 128.000000', '1 4 0', 0, 0);
		make_way('-217.000000 -1681.000000 128.000000', '3 5 0', 0, 0);
		make_way('-84.000000 -1673.000000 128.000000', '4 6 0', 0, 0);
		make_way('86.000000 -1655.000000 128.000000', '5 7 0', 0, 0);
		make_way('237.000000 -1650.000000 128.000000', '6 8 9', 18, 0);
		make_way('366.000000 -1684.000000 128.000000', '7 9 0', 0, 0);
		make_way('551.000000 -1683.000000 128.000000', '8 10 7', 0, 0);
		make_way('573.000000 -1513.000000 128.000000', '9 11 0', 0, 0);
		make_way('526.000000 -1385.000000 128.000000', '10 12 17', 0, 0);
		make_way('444.000000 -1273.000000 128.000000', '11 13 0', 0, 0);
		make_way('387.000000 -1150.000000 128.000000', '12 14 0', 0, 0);
		make_way('461.000000 -1020.000000 128.000000', '13 15 0', 0, 0);
		make_way('577.000000 -944.000000 128.000000', '14 16 0', 0, 0);
		make_way('592.000000 -1073.000000 128.000000', '15 17 0', 0, 0);
		make_way('686.000000 -1169.000000 128.000000', '16 11 0', 0, 0);
		make_way('182.000000 -1518.000000 128.000000', '7 19 0', 0, 0);
		make_way('163.000000 -1384.000000 128.000000', '18 20 0', 0, 0);
		make_way('134.000000 -1220.000000 121.000000', '21 0 0', 0, 0);
		make_way('135.000000 -1086.000000 104.000000', '20 22 0', 0, 0);
		make_way('146.000000 -953.000000 87.000000', '21 23 0', 0, 0);
		make_way('156.000000 -821.000000 71.000000', '22 24 0', 0, 0);
		make_way('155.000000 -687.000000 64.000000', '23 25 0', 0, 0);
		make_way('129.000000 -550.000000 64.000000', '24 26 0', 0, 0);
		make_way('113.000000 -362.000000 64.000000', '25 27 0', 0, 0);
		make_way('133.000000 -226.000000 64.000000', '26 28 0', 0, 0);
		make_way('132.000000 -93.000000 64.000000', '27 29 0', 0, 0);
		make_way('134.000000 40.000000 64.000000', '28 30 0', 0, 0);
		make_way('136.000000 174.000000 64.000000', '29 31 0', 0, 0);
		make_way('137.000000 307.000000 64.000000', '30 32 0', 0, 0);
		make_way('138.000000 440.000000 64.000000', '31 33 0', 0, 0);
		make_way('166.000000 577.000000 64.000000', '32 34 0', 0, 0);
		make_way('292.000000 647.000000 64.000000', '33 35 0', 0, 0);
		make_way('426.000000 655.000000 64.000000', '34 36 0', 0, 0);
		make_way('559.000000 663.000000 64.000000', '35 37 0', 0, 0);
		make_way('694.000000 679.000000 64.000000', '36 38 68', 0, 0);
		make_way('827.000000 632.000000 64.000000', '37 39 0', 0, 0);
		make_way('935.000000 540.000000 64.000000', '38 40 0', 0, 0);
		make_way('1069.000000 511.000000 64.000000', '39 41 0', 0, 0);
		make_way('1206.000000 536.000000 64.000000', '40 42 0', 0, 0);
		make_way('1343.000000 528.000000 64.000000', '41 43 0', 0, 0);
		make_way('1472.000000 564.000000 64.000000', '42 44 0', 0, 0);
		make_way('1600.000000 600.000000 64.000000', '43 45 0', 0, 0);
		make_way('1732.000000 624.000000 64.000000', '44 46 0', 0, 0);
		make_way('1865.000000 634.000000 64.000000', '45 47 0', 0, 0);
		make_way('686.000000 -1169.000000 128.000000', '16 11 0', 0, 0);
		make_way('182.000000 -1518.000000 128.000000', '7 19 0', 0, 0);
		make_way('163.000000 -1384.000000 128.000000', '18 20 0', 0, 0);
		make_way('134.000000 -1220.000000 121.000000', '21 0 0', 0, 0);
		make_way('135.000000 -1086.000000 104.000000', '20 22 0', 0, 0);
		make_way('146.000000 -953.000000 87.000000', '21 23 0', 0, 0);
		make_way('156.000000 -821.000000 71.000000', '22 24 0', 0, 0);
		make_way('155.000000 -687.000000 64.000000', '23 25 0', 0, 0);
		make_way('129.000000 -550.000000 64.000000', '24 26 0', 0, 0);
		make_way('113.000000 -362.000000 64.000000', '25 27 0', 0, 0);
		make_way('133.000000 -226.000000 64.000000', '26 28 0', 0, 0);
		make_way('132.000000 -93.000000 64.000000', '27 29 0', 0, 0);
		make_way('134.000000 40.000000 64.000000', '28 30 0', 0, 0);
		make_way('136.000000 174.000000 64.000000', '29 31 0', 0, 0);
		make_way('137.000000 307.000000 64.000000', '30 32 0', 0, 0);
		make_way('138.000000 440.000000 64.000000', '31 33 0', 0, 0);
		make_way('166.000000 577.000000 64.000000', '32 34 0', 0, 0);
		make_way('292.000000 647.000000 64.000000', '33 35 0', 0, 0);
		make_way('426.000000 655.000000 64.000000', '34 36 0', 0, 0);
		make_way('559.000000 663.000000 64.000000', '35 37 0', 0, 0);
		make_way('694.000000 679.000000 64.000000', '36 38 68', 0, 0);
		make_way('827.000000 632.000000 64.000000', '37 39 0', 0, 0);
		make_way('935.000000 540.000000 64.000000', '38 40 0', 0, 0);
		make_way('1069.000000 511.000000 64.000000', '39 41 0', 0, 0);
		make_way('1206.000000 536.000000 64.000000', '40 42 0', 0, 0);
		make_way('1343.000000 528.000000 64.000000', '41 43 0', 0, 0);
		make_way('1472.000000 564.000000 64.000000', '42 44 0', 0, 0);
		make_way('1600.000000 600.000000 64.000000', '43 45 0', 0, 0);
		make_way('1732.000000 624.000000 64.000000', '44 46 0', 0, 0);
		make_way('1865.000000 634.000000 64.000000', '45 47 0', 0, 0);
		make_way('1998.000000 634.000000 64.000000', '46 48 0', 0, 0);
		make_way('2131.000000 629.000000 64.000000', '47 49 50', 0, 0);
		make_way('2265.000000 623.000000 64.000000', '48 0 0', 0, 0);
		make_way('2014.000000 777.000000 64.000000', '48 51 0', 0, 0);
		make_way('1919.000000 875.000000 64.000000', '50 52 0', 0, 0);
		make_way('1784.000000 863.000000 64.000000', '51 53 0', 0, 0);
		make_way('1642.000000 885.000000 64.000000', '52 54 0', 0, 0);
		make_way('1654.000000 1059.000000 64.000000', '53 55 0', 0, 0);
		make_way('1788.000000 1087.000000 96.000000', '54 56 60', 0, 0);
		make_way('1921.000000 1083.000000 96.000000', '55 57 0', 0, 0);
		make_way('2055.000000 1074.000000 96.000000', '56 58 0', 0, 0);
		make_way('2188.000000 1069.000000 96.000000', '57 59 0', 0, 0);
		make_way('2306.000000 1137.000000 96.000000', '58 0 0', 0, 0);
		make_way('1626.000000 1241.000000 64.000000', '61 0 0', 0, 0);
		make_way('1465.000000 1310.000000 64.000000', '60 62 0', 0, 0);
		make_way('1340.000000 1262.000000 96.000000', '61 63 0', 0, 0);
		make_way('1205.000000 1266.000000 96.000000', '62 64 0', 0, 0);
		make_way('1071.000000 1234.000000 96.000000', '63 65 0', 0, 0);
		make_way('935.000000 1247.000000 96.000000', '64 66 0', 0, 0);
		make_way('801.000000 1252.000000 96.000000', '65 67 0', 0, 0);
		make_way('667.000000 1213.000000 96.000000', '66 68 0', 0, 0);
		make_way('613.000000 1077.000000 96.000000', '67 37 0', 0, 0);
		make_way('487.000000 1269.000000 96.000000', '70 0 0', 0, 0);
		make_way('349.000000 1260.000000 96.000000', '69 71 0', 0, 0);
		make_way('214.000000 1255.000000 96.000000', '70 72 0', 0, 0);
		make_way('78.000000 1245.000000 96.000000', '71 73 0', 0, 0);
		make_way('-50.000000 1299.000000 96.000000', '72 74 76', 0, 0);
		make_way('-149.000000 1394.000000 96.000000', '73 75 77', 0, 0);
		make_way('-164.000000 1537.000000 96.000000', '74 76 0', 0, 0);
		make_way('7.000000 1555.000000 96.000000', '75 73 168', 0, 0);
		make_way('-316.000000 1399.000000 96.000000', '74 78 0', 0, 0);
		make_way('1998.000000 634.000000 64.000000', '46 48 0', 0, 0);
		make_way('2131.000000 629.000000 64.000000', '47 49 50', 0, 0);
		make_way('2265.000000 623.000000 64.000000', '48 0 0', 0, 0);
		make_way('2014.000000 777.000000 64.000000', '48 51 0', 0, 0);
		make_way('1919.000000 875.000000 64.000000', '50 52 0', 0, 0);
		make_way('1784.000000 863.000000 64.000000', '51 53 0', 0, 0);
		make_way('1642.000000 885.000000 64.000000', '52 54 0', 0, 0);
		make_way('1654.000000 1059.000000 64.000000', '53 55 0', 0, 0);
		make_way('1788.000000 1087.000000 96.000000', '54 56 60', 0, 0);
		make_way('1921.000000 1083.000000 96.000000', '55 57 0', 0, 0);
		make_way('2055.000000 1074.000000 96.000000', '56 58 0', 0, 0);
		make_way('2188.000000 1069.000000 96.000000', '57 59 0', 0, 0);
		make_way('2306.000000 1137.000000 96.000000', '58 0 0', 0, 0);
		make_way('1626.000000 1241.000000 64.000000', '61 0 0', 0, 0);
		make_way('1465.000000 1310.000000 64.000000', '60 62 0', 0, 0);
		make_way('1340.000000 1262.000000 96.000000', '61 63 0', 0, 0);
		make_way('1205.000000 1266.000000 96.000000', '62 64 0', 0, 0);
		make_way('1071.000000 1234.000000 96.000000', '63 65 0', 0, 0);
		make_way('935.000000 1247.000000 96.000000', '64 66 0', 0, 0);
		make_way('801.000000 1252.000000 96.000000', '65 67 0', 0, 0);
		make_way('667.000000 1213.000000 96.000000', '66 68 0', 0, 0);
		make_way('613.000000 1077.000000 96.000000', '67 37 0', 0, 0);
		make_way('487.000000 1269.000000 96.000000', '70 0 0', 0, 0);
		make_way('349.000000 1260.000000 96.000000', '69 71 0', 0, 0);
		make_way('214.000000 1255.000000 96.000000', '70 72 0', 0, 0);
		make_way('78.000000 1245.000000 96.000000', '71 73 0', 0, 0);
		make_way('-50.000000 1299.000000 96.000000', '72 74 76', 0, 0);
		make_way('-149.000000 1394.000000 96.000000', '73 75 77', 0, 0);
		make_way('-164.000000 1537.000000 96.000000', '74 76 0', 0, 0);
		make_way('7.000000 1555.000000 96.000000', '75 73 168', 0, 0);
		make_way('-316.000000 1399.000000 96.000000', '74 78 0', 0, 0);
		make_way('-449.000000 1408.000000 96.000000', '77 79 0', 0, 0);
		make_way('-583.000000 1412.000000 96.000000', '78 80 0', 0, 0);
		make_way('-716.000000 1410.000000 96.000000', '79 81 0', 0, 0);
		make_way('-876.000000 1393.000000 64.000000', '82 0 0', 0, 0);
		make_way('-808.000000 1217.000000 64.000000', '81 83 0', 0, 0);
		make_way('-822.000000 1078.000000 64.000000', '82 84 0', 0, 0);
		make_way('-828.000000 941.000000 70.000000', '83 85 0', 0, 0);
		make_way('-720.000000 835.000000 68.000000', '84 86 0', 0, 0);
		make_way('-587.000000 830.000000 64.000000', '85 87 0', 0, 0);
		make_way('-453.000000 820.000000 64.000000', '86 88 0', 0, 0);
		make_way('-320.000000 819.000000 64.000000', '87 89 0', 0, 0);
		make_way('-187.000000 824.000000 64.000000', '88 90 0', 0, 0);
		make_way('-53.000000 830.000000 64.000000', '89 91 0', 0, 0);
		make_way('80.000000 824.000000 64.000000', '90 92 0', 0, 0);
		make_way('215.000000 833.000000 64.000000', '91 93 0', 0, 0);
		make_way('-289.000000 644.000000 24.000000', '94 0 0', 0, 0);
		make_way('-423.000000 642.000000 -10.000000', '95 0 0', 0, 0);
		make_way('-556.000000 641.000000 -43.000000', '96 0 0', 0, 0);
		make_way('-690.000000 641.000000 -76.000000', '97 0 0', 0, 0);
		make_way('-823.000000 642.000000 -110.000000', '98 0 0', 0, 0);
		make_way('-1009.000000 648.000000 -128.000000', '99 0 0', 0, 0);
		make_way('-1061.000000 818.000000 -128.000000', '98 100 0', 0, 0);
		make_way('-1082.000000 952.000000 -128.000000', '99 101 0', 0, 0);
		make_way('-1075.000000 1085.000000 -128.000000', '100 102 0', 0, 0);
		make_way('-1066.000000 1218.000000 -128.000000', '101 103 0', 0, 0);
		make_way('-1057.000000 1351.000000 -128.000000', '102 104 0', 0, 0);
		make_way('-1051.000000 1484.000000 -128.000000', '103 105 0', 0, 0);
		make_way('-1055.000000 1618.000000 -128.000000', '104 106 0', 0, 0);
		make_way('-1062.000000 1751.000000 -128.000000', '105 107 0', 0, 0);
		make_way('-1091.000000 1924.000000 -128.000000', '106 108 0', 0, 0);
		make_way('-1065.000000 2103.000000 -128.000000', '107 109 0', 0, 0);
		make_way('-449.000000 1408.000000 96.000000', '77 79 0', 0, 0);
		make_way('-583.000000 1412.000000 96.000000', '78 80 0', 0, 0);
		make_way('-716.000000 1410.000000 96.000000', '79 81 0', 0, 0);
		make_way('-876.000000 1393.000000 64.000000', '82 0 0', 0, 0);
		make_way('-808.000000 1217.000000 64.000000', '81 83 0', 0, 0);
		make_way('-822.000000 1078.000000 64.000000', '82 84 0', 0, 0);
		make_way('-828.000000 941.000000 70.000000', '83 85 0', 0, 0);
		make_way('-720.000000 835.000000 68.000000', '84 86 0', 0, 0);
		make_way('-587.000000 830.000000 64.000000', '85 87 0', 0, 0);
		make_way('-453.000000 820.000000 64.000000', '86 88 0', 0, 0);
		make_way('-320.000000 819.000000 64.000000', '87 89 0', 0, 0);
		make_way('-187.000000 824.000000 64.000000', '88 90 0', 0, 0);
		make_way('-53.000000 830.000000 64.000000', '89 91 0', 0, 0);
		make_way('80.000000 824.000000 64.000000', '90 92 0', 0, 0);
		make_way('215.000000 833.000000 64.000000', '91 93 0', 0, 0);
		make_way('-289.000000 644.000000 24.000000', '94 0 0', 0, 0);
		make_way('-423.000000 642.000000 -10.000000', '95 0 0', 0, 0);
		make_way('-556.000000 641.000000 -43.000000', '96 0 0', 0, 0);
		make_way('-690.000000 641.000000 -76.000000', '97 0 0', 0, 0);
		make_way('-823.000000 642.000000 -110.000000', '98 0 0', 0, 0);
		make_way('-1009.000000 648.000000 -128.000000', '99 0 0', 0, 0);
		make_way('-1061.000000 818.000000 -128.000000', '98 100 0', 0, 0);
		make_way('-1082.000000 952.000000 -128.000000', '99 101 0', 0, 0);
		make_way('-1075.000000 1085.000000 -128.000000', '100 102 0', 0, 0);
		make_way('-1066.000000 1218.000000 -128.000000', '101 103 0', 0, 0);
		make_way('-1057.000000 1351.000000 -128.000000', '102 104 0', 0, 0);
		make_way('-1051.000000 1484.000000 -128.000000', '103 105 0', 0, 0);
		make_way('-1055.000000 1618.000000 -128.000000', '104 106 0', 0, 0);
		make_way('-1062.000000 1751.000000 -128.000000', '105 107 0', 0, 0);
		make_way('-1091.000000 1924.000000 -128.000000', '106 108 0', 0, 0);
		make_way('-1065.000000 2103.000000 -128.000000', '107 109 0', 0, 0);
		make_way('-1068.000000 2236.000000 -128.000000', '108 110 0', 0, 0);
		make_way('-1067.000000 2370.000000 -112.000000', '109 111 0', 0, 0);
		make_way('-1066.000000 2503.000000 -78.000000', '110 112 0', 0, 0);
		make_way('-1065.000000 2636.000000 -45.000000', '111 113 0', 0, 0);
		make_way('-1065.000000 2770.000000 -12.000000', '112 114 0', 0, 0);
		make_way('-1064.000000 2903.000000 22.000000', '113 115 0', 0, 0);
		make_way('-1063.000000 3036.000000 55.000000', '114 116 0', 0, 0);
		make_way('-1069.000000 3172.000000 64.000000', '115 117 0', 0, 0);
		make_way('-1039.000000 3306.000000 64.000000', '116 118 0', 0, 0);
		make_way('-978.000000 3446.000000 64.000000', '117 119 0', 0, 0);
		make_way('-843.000000 3451.000000 64.000000', '118 120 0', 0, 0);
		make_way('-710.000000 3459.000000 64.000000', '119 121 0', 0, 0);
		make_way('-577.000000 3460.000000 64.000000', '120 122 0', 0, 0);
		make_way('-443.000000 3460.000000 64.000000', '121 123 0', 0, 0);
		make_way('-310.000000 3461.000000 64.000000', '122 124 0', 0, 0);
		make_way('-177.000000 3462.000000 64.000000', '123 125 0', 0, 0);
		make_way('-43.000000 3463.000000 64.000000', '124 126 0', 0, 0);
		make_way('90.000000 3465.000000 64.000000', '125 127 0', 0, 0);
		make_way('223.000000 3467.000000 64.000000', '128 0 0', 0, 0);
		make_way('343.000000 3469.000000 42.000000', '129 0 0', 0, 0);
		make_way('477.000000 3471.000000 9.000000', '130 0 0', 0, 0);
		make_way('610.000000 3473.000000 -25.000000', '131 0 0', 0, 0);
		make_way('744.000000 3474.000000 -58.000000', '132 0 0', 0, 0);
		make_way('879.000000 3483.000000 -64.000000', '131 133 0', 0, 0);
		make_way('1016.000000 3470.000000 -64.000000', '132 134 0', 0, 0);
		make_way('1152.000000 3458.000000 -64.000000', '133 135 0', 0, 0);
		make_way('1281.000000 3498.000000 -64.000000', '134 136 0', 0, 0);
		make_way('1417.000000 3510.000000 -64.000000', '135 137 0', 0, 0);
		make_way('1547.000000 3467.000000 -64.000000', '136 138 0', 0, 0);
		make_way('1627.000000 3349.000000 -64.000000', '137 139 0', 0, 0);
		make_way('1656.000000 3219.000000 -64.000000', '138 140 0', 0, 0);
		make_way('-1068.000000 2236.000000 -128.000000', '108 110 0', 0, 0);
		make_way('-1067.000000 2370.000000 -112.000000', '109 111 0', 0, 0);
		make_way('-1066.000000 2503.000000 -78.000000', '110 112 0', 0, 0);
		make_way('-1065.000000 2636.000000 -45.000000', '111 113 0', 0, 0);
		make_way('-1065.000000 2770.000000 -12.000000', '112 114 0', 0, 0);
		make_way('-1064.000000 2903.000000 22.000000', '113 115 0', 0, 0);
		make_way('-1063.000000 3036.000000 55.000000', '114 116 0', 0, 0);
		make_way('-1069.000000 3172.000000 64.000000', '115 117 0', 0, 0);
		make_way('-1039.000000 3306.000000 64.000000', '116 118 0', 0, 0);
		make_way('-978.000000 3446.000000 64.000000', '117 119 0', 0, 0);
		make_way('-843.000000 3451.000000 64.000000', '118 120 0', 0, 0);
		make_way('-710.000000 3459.000000 64.000000', '119 121 0', 0, 0);
		make_way('-577.000000 3460.000000 64.000000', '120 122 0', 0, 0);
		make_way('-443.000000 3460.000000 64.000000', '121 123 0', 0, 0);
		make_way('-310.000000 3461.000000 64.000000', '122 124 0', 0, 0);
		make_way('-177.000000 3462.000000 64.000000', '123 125 0', 0, 0);
		make_way('-43.000000 3463.000000 64.000000', '124 126 0', 0, 0);
		make_way('90.000000 3465.000000 64.000000', '125 127 0', 0, 0);
		make_way('223.000000 3467.000000 64.000000', '128 0 0', 0, 0);
		make_way('343.000000 3469.000000 42.000000', '129 0 0', 0, 0);
		make_way('477.000000 3471.000000 9.000000', '130 0 0', 0, 0);
		make_way('610.000000 3473.000000 -25.000000', '131 0 0', 0, 0);
		make_way('744.000000 3474.000000 -58.000000', '132 0 0', 0, 0);
		make_way('879.000000 3483.000000 -64.000000', '131 133 0', 0, 0);
		make_way('1016.000000 3470.000000 -64.000000', '132 134 0', 0, 0);
		make_way('1152.000000 3458.000000 -64.000000', '133 135 0', 0, 0);
		make_way('1281.000000 3498.000000 -64.000000', '134 136 0', 0, 0);
		make_way('1417.000000 3510.000000 -64.000000', '135 137 0', 0, 0);
		make_way('1547.000000 3467.000000 -64.000000', '136 138 0', 0, 0);
		make_way('1627.000000 3349.000000 -64.000000', '137 139 0', 0, 0);
		make_way('1656.000000 3219.000000 -64.000000', '138 140 0', 0, 0);
		make_way('1662.000000 3084.000000 -63.000000', '139 141 0', 0, 0);
		make_way('1512.000000 2969.000000 -64.000000', '140 142 0', 0, 0);
		make_way('1377.000000 2984.000000 -64.000000', '141 143 0', 0, 0);
		make_way('1241.000000 2955.000000 -48.000000', '142 144 0', 0, 0);
		make_way('1108.000000 2960.000000 16.000000', '143 145 0', 0, 0);
		make_way('974.000000 2967.000000 64.000000', '144 146 0', 0, 0);
		make_way('842.000000 2978.000000 64.000000', '145 147 0', 0, 0);
		make_way('710.000000 3000.000000 64.000000', '146 148 0', 0, 0);
		make_way('579.000000 3027.000000 64.000000', '147 149 0', 0, 0);
		make_way('477.000000 3121.000000 64.000000', '148 150 0', 0, 0);
		make_way('289.000000 3143.000000 64.000000', '149 151 0', 0, 0);
		make_way('185.000000 3056.000000 64.000000', '150 152 0', 0, 0);
		make_way('19.000000 3138.000000 64.000000', '151 153 0', 0, 0);
		make_way('-52.000000 3256.000000 64.000000', '152 154 0', 0, 0);
		make_way('-191.000000 3250.000000 64.000000', '153 155 0', 0, 0);
		make_way('-226.000000 3108.000000 64.000000', '154 156 0', 0, 0);
		make_way('-122.000000 3008.000000 64.000000', '155 157 0', 0, 0);
		make_way('660.000000 2831.000000 64.000000', '158 0 0', 0, 0);
		make_way('644.000000 2696.000000 64.000000', '157 159 0', 0, 0);
		make_way('628.000000 2563.000000 64.000000', '158 160 0', 0, 0);
		make_way('645.000000 2429.000000 64.000000', '159 161 0', 0, 0);
		make_way('668.000000 2294.000000 64.000000', '160 162 0', 0, 0);
		make_way('578.000000 2191.000000 64.000000', '161 163 0', 0, 0);
		make_way('441.000000 2183.000000 64.000000', '162 164 0', 0, 0);
		make_way('309.000000 2197.000000 64.000000', '163 165 0', 0, 0);
		make_way('175.000000 2206.000000 64.000000', '164 166 0', 0, 0);
		make_way('-4.000000 2197.000000 64.000000', '165 167 0', 0, 0);
		make_way('10.000000 2032.000000 96.000000', '166 168 0', 0, 0);
		make_way('29.000000 1900.000000 96.000000', '167 76 0', 0, 0);
 }

/*
	if (mapname == "dm1")
		map_dm1();
	else if (mapname == "dm2")
		map_dm2();
	else if (mapname == "dm3")
		map_dm3();
	else if (mapname == "dm4")
		map_dm4();
	else if (mapname == "dm5")
		map_dm5();
	else if (mapname == "dm6")
		map_dm6();
*/
};

/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Variables and shtuff

bot.qc has become pretty much a header file
for all variable in the bot...

-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
*/

// ----- entity fields ---
.float	wallhug, keys, oldkeys, ishuman;
.float	b_frags, b_clientno, b_shirt, b_pants; 
.float	priority, ai_time, b_sound, missile_speed;
.float	portal_time, b_skill, switch_wallhug;
.float	b_aiflags, b_num, b_chattime;
.float	b_menu, b_menu_time, b_menu_value;
.float route_failed, dyn_flags, dyn_time;
.float dyn_plat;
.entity	temp_way, last_way, phys_obj;
.entity	target1, target2, target3, target4;
.entity	_next, _last;
.entity	current_way;
.vector	b_angle, b_dest, mouse_emu, obs_dir;
.vector	movevect, b_dir;
.vector dyn_dest;

// --------defines-----
float SVC_UPDATENAME	= 13;
float SVC_UPDATEFRAGS	= 14;
float SVC_UPDATECOLORS	= 17;

// used for the physics & movement AI
float KEY_MOVEUP 		= 1;
float KEY_MOVEDOWN 	= 2;
float KEY_MOVELEFT 	= 4;
float KEY_MOVERIGHT 	= 8;
float KEY_MOVEFORWARD	= 16;
float KEY_MOVEBACK	= 32;
float KEY_LOOKUP		= 64;
float KEY_LOOKDOWN	= 128;
float KEY_LOOKLEFT	= 256;
float KEY_LOOKRIGHT	= 512;

// these are aiflags for waypoints
// some overlap to the bot
float AI_TELELINK_1	= 1; // link type
float AI_TELELINK_2	= 2; // link type
float AI_TELELINK_3	= 4; // link type
float AI_TELELINK_4	= 8; // link type
float AI_DOORFLAG		= 16; // read ahead
float AI_PRECISION	= 32; // read ahead + point
float AI_SURFACE		= 64; // point 
float AI_BLIND		= 128; // read ahead + point
float AI_JUMP		= 256; // point + ignore
float AI_DIRECTIONAL	= 512; // read ahead + ignore
float AI_PLAT_BOTTOM	= 1024; // read ahead 
float AI_RIDE_TRAIN	= 2048; // read ahead 
float AI_SUPER_JUMP	= 4096; // point + ignore + route test
float AI_SNIPER		= 8192; // point type 
float AI_AMBUSH		= 16384; // point type
float AI_DOOR_NO_OPEN	= 32768; // read ahead
float AI_DIFFICULT	= 65536; // route test
float AI_TRACE_TEST	= 131072; // route test

// these are flags for bots/players (dynamic/editor flags)
float AI_OBSTRUCTED	= 1;
float AI_HOLD_SELECT	= 2;
float AI_ROUTE_FAILED	= 2;
float AI_WAIT		= 4;
float AI_DANGER		= 8;


// addition masks
float AI_POINT_TYPES 	= 29152;
float AI_READAHEAD_TYPES	= 36528;
float AI_IGNORE_TYPES	= 4864;

float WM_UNINIT		= 0;
float WM_DYNAMIC		= 1;
float WM_LOADING		= 2;
float WM_LOADED		= 3;
float WM_EDITOR		= 4;
float WM_EDITOR_DYNAMIC	= 5;
float WM_EDITOR_DYNLINK	= 6;


float OPT_SAVEBOTS	= 1;
float OPT_NOCHAT	= 2;

// -------globals-----
float 	active_clients;
float		max_clients, real_frametime;
float		bot_count, b_options;
float		waypoint_mode, dump_mode; 
float		waypoints, direct_route;
float		sv_friction, sv_gravity;
float		sv_accelerate, sv_maxspeed, sv_stopspeed;
entity	fixer;
entity	route_table;
entity	b_temp1, b_temp2, b_temp3;
entity 	player_head, phys_head, way_head;
float		busy_waypoints;
float		saved_bots, saved_skills1, saved_skills2, current_bots;

// -------ProtoTypes------
// external
void()				ClientConnect;
void()				ClientDisconnect;
void()				SetNewParms;
void()				PutClientCTInServer;
void()				PutClientTInServer;
// rankings
float(float clientno)		ClientBitFlag;
float()				ClientNextAvailable;
void(float whichteam, float whatbot, float whatskill) BotConnect;
void(entity bot)			BotDisconnect;
void(float clientno)		BotInvalidClientNo;
void(entity who)			UpdateClient;

// waypointing
void()				DynamicWaypoint;
entity(vector org)		make_waypoint;
void()				ClearAllWays;
void()				FixWaypoints;
float()				begin_route;
void(entity this, float direct)			bot_get_path;
void()				WaypointThink;
entity(entity start)				FindWayPoint;

// physics & movement
float(entity e)			bot_can_rj;
void()				bot_jump;
void()				frik_bot_roam;
float(vector weird)		frik_walkmove;
void()				frik_movetogoal;
void()				frik_obstacles;
float(float flag)			frik_recognize_plat;
float(vector sdir)		frik_KeysForDir;
void(vector whichway, float danger) frik_obstructed;
void()				SV_Physics_Client;
void()				SV_ClientThink;
void() 				CL_KeyMove;

// ai & misc
string()				PickARandomName;
float(entity targ)		fov_2;
float(float y1, float y2)	angcomp;
float(entity targ1, entity targ2)		wisible;
float(entity targ)		sisible;
float(entity targ)		fisible;
vector(entity ent)		realorigin;
void(entity ent)			target_drop;
void(entity ent)			target_add;
void()				KickABot;
void()				BotImpulses;
void(entity targ, float success) bot_lost;
string(float r)			BotName;
float(float v)			frik_anglemod;
void() bot_chat;
void(float tpic) bot_start_topic;


// editor stuffs

void()				bot_way_edit;
void()				bot_menu_display;


// ----------Commands---------
void(entity e, float chan, string samp, float vol, float atten) frik_sound = #8;
void(entity client, string s)	frik_stuffcmd = #21;
void(entity client, string s)	frik_sprint = #24;
vector(entity e, float sped)	frik_aim = #44;	
void(entity client, string s)	frik_centerprint = #73;
void(entity e)			frik_setspawnparms = #78;
void(float to, float f)		frik_WriteByte = #52;
void(float to, float f)		frik_WriteChar = #53;
void(float to, float f)		frik_WriteShort = #54;
void(float to, float f)		frik_WriteLong = #55;
void(float to, float f)		frik_WriteCoord = #56;
void(float to, float f)		frik_WriteAngle = #57;
void(float to, string s)	frik_WriteString	= #58;
void(float to, entity s)	frik_WriteEntity	= #59;

void(entity client, string s1, string s2, string s3, string s4, string s5, string s6, string s7)
frik_big_centerprint = #73;

//----------------------------------------------------------------------------

/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Function redclarations. These allow function 
designed to work for clients (sprint, so forth)
to mainly not complain when working with a bot

Although these shouldn't be needed anymore,
as the bots truly are clients now, if you don't
stop the SZ_ buffer from filling up by disabling
direct messages to the bots, it crashes quake :-(

-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
*/
void(entity	client, string s) stuffcmd =
{
	if (client.ishuman == 1)
		frik_stuffcmd(client, s);
	b_temp1 = player_head;

	while(b_temp1)
	{
		if (b_temp1.classname == "botcam")
		{
			if ((b_temp1.enemy == client) && b_temp1.ishuman)
				frik_stuffcmd(b_temp1, s);
		}
		b_temp1 = b_temp1._next;
	}
};

void(entity	e) setspawnparms =
{
	if (e.ishuman == 1)
		frik_setspawnparms(e);
	else
	{
		b_temp1 = player_head;
		while(b_temp1)
		{
			if (b_temp1.ishuman)
			{
				frik_setspawnparms(b_temp1);
				return;
			}
			b_temp1 = b_temp1._next;
		}
		SetNewParms();
	}
};
void(entity	client, string s) sprint =
{
	if (client.ishuman == 1)
		frik_sprint(client, s);
	b_temp1 = player_head;

	while(b_temp1)
	{
		if (b_temp1.classname == "botcam")
		{
			if ((b_temp1.enemy == client) && b_temp1.ishuman)
				frik_sprint(b_temp1, s);
		}
		b_temp1 = b_temp1._next;
	}

};
void(entity	client, string s) centerprint =
{
	if (client.ishuman == 1)
		frik_centerprint(client, s);
	b_temp1 = player_head;

	while(b_temp1)
	{
		if (b_temp1.classname == "botcam")
		{
			if ((b_temp1.enemy == client) && b_temp1.ishuman)
				frik_centerprint(b_temp1, s);
		}
		b_temp1 = b_temp1._next;
	}
};

vector(entity e, float sped) aim =
{
	e.missile_speed = sped;
	return frik_aim(e, sped);
};

void(entity e, float chan, string samp, float vol, float atten) sound = 
{

	frik_sound(e, chan, samp, vol, atten);
	if (samp == "items/inv3.wav")
		return;
	else if (e.classname == "player")
		e.b_sound = time + 1;
	else if (other.classname == "player")
		other.b_sound = time + 1;

};
void(float to, float f) WriteByte =
{
	if ((to == MSG_ONE) && (msg_entity.ishuman != TRUE))
		return;
	frik_WriteByte(to, f);
};
void(float to, float f) WriteChar =		
{
	if ((to == MSG_ONE) && (msg_entity.ishuman != TRUE))
		return;
	frik_WriteChar(to, f);
};
void(float to, float f) WriteShort =	
{
	if ((to == MSG_ONE) && (msg_entity.ishuman != TRUE))
		return;
	frik_WriteShort(to, f);
};
void(float to, float f) WriteLong = 
{
	if ((to == MSG_ONE) && (msg_entity.ishuman != TRUE))
		return;
	frik_WriteLong(to, f);
};
void(float to, float f) WriteCoord = 
{
	if ((to == MSG_ONE) && (msg_entity.ishuman != TRUE))
		return;
	frik_WriteCoord(to, f);
};
void(float to, float f) WriteAngle = 
{
	if ((to == MSG_ONE) && (msg_entity.ishuman != TRUE))
		return;
	frik_WriteAngle(to, f);
};
void(float to, string s) WriteString = 
{
	if ((to == MSG_ONE) && (msg_entity.ishuman != TRUE))
		return;
	frik_WriteString(to, s);
};
void(float to, entity s) WriteEntity = 
{
	if ((to == MSG_ONE) && (msg_entity.ishuman != TRUE))
		return;
	frik_WriteEntity(to, s);
};
/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Bot Cam, see what the bot sees (or any other player)

-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
*/

float() botcam =
{
	if (self.classname != "botcam")
		return FALSE;
	setorigin(self, self.enemy.origin);
	self.items = self.enemy.items;
	self.weapon = self.enemy.weapon;
	self.weaponmodel = self.enemy.weaponmodel;
	self.currentammo = self.enemy.currentammo;
	self.weaponframe = self.enemy.weaponframe;
	self.ammo_shells = self.enemy.ammo_shells;
	self.ammo_nails = self.enemy.ammo_nails;
	self.ammo_rockets= self.enemy.ammo_rockets;
	self.ammo_cells = self.enemy.ammo_cells;
	self.view_ofs = self.enemy.view_ofs;
	self.health = self.enemy.health;
	self.armorvalue = self.enemy.armorvalue;
	self.dmg_take = self.enemy.dmg_take;
	self.dmg_save = self.enemy.dmg_save;
	self.dmg_inflictor = self.enemy.dmg_inflictor;
	self.punchangle = self.enemy.punchangle;
	self.deadflag = self.enemy.deadflag;
	msg_entity = self;
	WriteByte (MSG_ONE,5);
	WriteEntity (MSG_ONE, self.enemy); 
	WriteByte (MSG_ONE, 10);
     	WriteAngle (MSG_ONE,self.enemy.v_angle_x);
     	WriteAngle (MSG_ONE,self.enemy.v_angle_y);
     	WriteAngle (MSG_ONE,self.enemy.v_angle_z);
	self.modelindex = 0;
	
	self.impulse = 0;	
	return TRUE;
	
};

void() botcam_u = 
{

	// sloppy cycling code
	if (self.classname != "botcam")
	{
		self.enemy = player_head;
	}
	else
	{
		do
			self.enemy = self.enemy._next;
		while (self.enemy.classname == "botcam");
	}
	if (self.enemy == self)
	{
		do
			self.enemy = self.enemy._next;
		while (self.enemy.classname == "botcam");
	}

	self.classname = "botcam";
	self.solid = SOLID_NOT;
	self.movetype = MOVETYPE_NONE;
	self.takedamage = DAMAGE_NO;


	if (!self.enemy)
	{
		sprint(self, "No one left to track!\n");
		msg_entity = self;
		WriteByte (MSG_ONE,5);
		WriteEntity (MSG_ONE, self);
		PutClientInServer();
		return;
	}
	if (!self.enemy.ishuman)
	{
		self.enemy.dmg_take = 0;
		self.enemy.dmg_save = 0;
	}
	sprint(self, "Now tracking ");
	sprint(self, self.enemy.netname);
	sprint(self, "\n");
};



/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Stuff mentioned up top
it just links the bot into the mod

-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
*/

void() ClientFixRankings =
{
	local float cno;

	if (self.switch_wallhug > time)
		return;
	self.switch_wallhug = 0;

	b_temp2 = nextent(world);
	cno = 0;

	while (cno < max_clients)
	{
		if ((!b_temp2.ishuman) && (active_clients & ClientBitFlag(cno)))
			UpdateClient(b_temp2);
		cno = cno + 1;
		b_temp2 = nextent(b_temp2);
	}
};
		
void() ClientInRankings =
{
	local float cno;

   	cno = self.colormap - 1;
	BotInvalidClientNo (cno);
	
	if (player_head)
		player_head._last = self;

	self._next = player_head;
	self._last = world;
	player_head = self;

	if (!self.phys_obj)
	{
		b_temp2 = phys_head;
		while (b_temp2 != world && b_temp2.owner != self)
			b_temp2 = b_temp2._next;
		self.phys_obj = b_temp2;
	}

	if (self.ishuman == 2)
	{
		self.ishuman = FALSE;
		return;
	}
	active_clients = active_clients | ClientBitFlag(cno);
	
	self.b_clientno = cno;
	self.ishuman = TRUE;
	self.switch_wallhug = time + 1;
};


void() ClientDisconnected =
{
	if (player_head == self)
		player_head = self._next;
	if (self._next)
		self._next._last = self._last;
	if (self._last)
		self._last._next = self._next;

	active_clients = active_clients - active_clients & ClientBitFlag(self.b_clientno);
};
/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

BotPreFrame & BotPostFrame, used to make the
bot easier to install

-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
*/
float () BotPreFrame =
{
	if (self.b_clientno == -1)
		return TRUE;
	if (self.ishuman)
	{
		if (self.switch_wallhug)
			ClientFixRankings();
		if (self.classname == "botcam")
			return TRUE;
		
	}
	if (self.b_frags != self.frags)
	{
		
		if (self.b_frags > self.frags)
		{
			if (pointcontents(self.origin) == CONTENT_LAVA)
				bot_start_topic(10);
			else
				bot_start_topic(9);
		}
		else
			bot_start_topic(2);
		self.b_frags = self.frags;
	}
	DynamicWaypoint();
	return FALSE;
};
float () BotPostFrame =
{
	if (self.b_clientno == -1)
		return TRUE;
	if (self.ishuman)
	{

		if (waypoint_mode > WM_LOADED)
			bot_menu_display();

		BotImpulses();

		if (botcam())
			return TRUE;
	}
	return FALSE;
};

/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Bot Chat code

The rest of this code is in bot_misc.qc

-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
*/
void(string h) BotSay = // simulate talking by composing a 'chat' message
{
	WriteByte(MSG_ALL, 8);
	WriteByte(MSG_ALL, 1);
	WriteString(MSG_ALL, self.netname);
	WriteByte(MSG_ALL, 8);
	WriteByte(MSG_ALL, 2);
	WriteString(MSG_ALL, h);
};
void() BotSayInit =
{
	WriteByte(MSG_ALL, 8);
	WriteByte(MSG_ALL, 1);
	WriteString(MSG_ALL, self.netname);
};
void(string h) BotSay2 =
{
	WriteByte(MSG_ALL, 8);
	WriteByte(MSG_ALL, 2);
	WriteString(MSG_ALL, h);
};
void(string h) BotSayTeam = 
{
	local entity t;
	if (!teamplay)
		return;
	t = player_head;
	while(t)
	{
		if (t.team == self.team)
		{
			msg_entity = t;
			WriteByte(MSG_ONE, 8);
			WriteByte(MSG_ONE, 1);
			WriteByte(MSG_ONE, 40);
			WriteString(MSG_ONE, self.netname);
			WriteByte(MSG_ONE, 8);
			WriteByte(MSG_ONE, 2);
			WriteByte(MSG_ONE, 41);
			WriteString(MSG_ONE, h);
		}
		t = t._next;
	}
};
/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

BotInit

-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
*/


void() BotInit =
{
	local entity ent, fisent;
	local float numents;
	
	// spawn entities for the physics
	ent = nextent(world);
	max_clients = 0;

	while(ent != world)
	{
		max_clients = max_clients + 1;
		ent = nextent(ent);
	}
	if (max_clients > 16)
		max_clients = 16;

	ent = nextent(world);
	fisent = world;
	while (numents < max_clients)
	{

		phys_head = spawn();
		if (fisent)
			fisent._next = phys_head;
		phys_head._last = fisent;
		fisent = phys_head;
		ent.phys_obj = phys_head;
		phys_head.classname = "phys_obj";
		phys_head.owner = ent;
		numents = numents + 1;
		ent = nextent(ent);
	}
	precache_model("sprites/s_light.spr");
	precache_model("sprites/s_bubble.spr");


};

/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Rankings 'utilities'. Written by Alan Kivlin,
this code just fools clients by sending precisely
the same network messages as when a real player
signs on to the server.

-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
*/


void(entity who) UpdateClient =
{
	WriteByte (MSG_ALL, SVC_UPDATENAME);
	WriteByte (MSG_ALL, who.b_clientno);
	WriteString (MSG_ALL, who.netname);
	WriteByte (MSG_ALL, SVC_UPDATECOLORS);
	WriteByte (MSG_ALL, who.b_clientno);
	WriteByte (MSG_ALL, who.b_shirt * 16 + who.b_pants);
	WriteByte (MSG_ALL, SVC_UPDATEFRAGS);
	WriteByte (MSG_ALL, who.b_clientno);
	WriteShort (MSG_ALL, who.frags);
};

float(float clientno) ClientBitFlag =
{
	// bigger, but faster
	if (clientno == 0)
		return 1;
	else if (clientno == 1)
		return 2;
	else if (clientno == 2)
		return 4;
	else if (clientno == 3)
		return 8;
	else if (clientno == 4)
		return 16;
	else if (clientno == 5)
		return 32;
	else if (clientno == 6)
		return 64;
	else if (clientno == 7)
		return 128;
	else if (clientno == 8)
		return 256;
	else if (clientno == 9)
		return 512;
	else if (clientno == 10)
		return 1024;
	else if (clientno == 11)
		return 2048;
	else if (clientno == 12)
		return 4096;
	else if (clientno == 13)
		return 8192;
	else if (clientno == 14)
		return 16384;
	else if (clientno == 15)
		return 32768;
	return 0;
};

float() ClientNextAvailable =
{
	local float clientno;

	clientno = max_clients;
	while(clientno > 0)
	{
		clientno = clientno - 1;

		if(!(active_clients & ClientBitFlag(clientno)))
			return clientno;
	}

	return -1;
};


void(entity e1, entity e2, float flag) DeveloperLightning =
{
	// used to show waypoint links for debugging
	WriteByte (MSG_BROADCAST, 23);
	if (flag)
		WriteByte (MSG_BROADCAST, 6);
	else
		WriteByte (MSG_BROADCAST, 13);
	WriteEntity (MSG_BROADCAST, e2);
	WriteCoord (MSG_BROADCAST, e1.origin_x);
	WriteCoord (MSG_BROADCAST, e1.origin_y);
	WriteCoord (MSG_BROADCAST, e1.origin_z);
	WriteCoord (MSG_BROADCAST, e2.origin_x);
	WriteCoord (MSG_BROADCAST, e2.origin_y);
	WriteCoord (MSG_BROADCAST, e2.origin_z); 
};

/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Find Another Color

Team finding code

-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
*/

float(float tcolor) FindAnotherColor =
{
	local float bestbet, scolor, pcount, bestp;
	bestbet = -1;
	bestp = 16;
	while(scolor < 14)
	{
		if (scolor != tcolor)
		{
			b_temp2 = player_head;
			pcount = 0;
			while(b_temp2 != world)
			{
				if (b_temp2.team == scolor + 1)
					pcount = pcount + 1;
				b_temp2 = b_temp2._next;
			}
			if ((pcount < bestp) && pcount)
			{
				bestbet = scolor;
				bestp = pcount;
			}
		}
		scolor = scolor + 1;
	}
	if (bestbet < 0)
	{
		bestbet = tcolor;
		while (bestbet == tcolor)
		{
			bestbet = floor(random() * 13);
		}
	}
	return bestbet;
};

/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

BotConnect and related functions.

-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
*/				
entity(float num) GetClientEntity =
{
	local entity upsy;
	upsy = world;
	num = num + 1;
	while (num > 0)
	{
		num = num - 1;
		upsy = nextent(upsy);
	} 
	return upsy;
};

void(float whichteam, float whatbot, float whatskill) BotConnect =
{
	local float f;
	local string h;
	local entity uself;
	
	f = ClientNextAvailable();
	uself = self;
	if(f == -1)
	{
		bprint("Unable to connect a bot, server is full.\n");
		return;
	}
	
	// chat thing

	bot_count = bot_count + 1;
	self = GetClientEntity(f);
	if (!saved_bots)
		bot_start_topic(1);
	self.b_clientno = f;
	self.colormap = f + 1;
	if (whatbot)
		self.netname = BotName(whatbot);
	else
		self.netname = PickARandomName();


	// players can set skill all weird, so leave these checks in
	whatskill = rint(whatskill);
	if (whatskill > 3)
		whatskill = 3;
	else if (whatskill < 0)
		whatskill = 0;
	self.b_skill = whatskill;
	
	/*
	if (teamplay && !coop)
	{
		if (whichteam)
			self.b_pants = FindAnotherColor(uself.team - 1);
		else
			self.b_pants = uself.team - 1;
		self.b_shirt = self.b_pants;
	}

	self.team = self.b_pants + 1;
	*/
	self.team = whichteam;
	UpdateClient(self);
//	SetNewParms();
	self.ishuman = 2;
	ClientConnect();
	if(self.team == T_SIDE)
		PutClientTInServer();
	else if(self.team == CT_SIDE)
		PutClientCTInServer();
		
	//PutClientInServer();

	active_clients = active_clients | ClientBitFlag(f);

	// this is risky... could corrupt .way files if done wrong
	// If you're not the gambling type, comment this out

	f = ClientBitFlag(self.b_num - 1);
	current_bots = current_bots | f;

	if (self.b_num <= 8)
		saved_skills1 = (saved_skills1 & (65536 - (3 * f)) | (self.b_skill * f));
	else
	{
		f = ClientBitFlag(self.b_num - 9);
		saved_skills2 = (saved_skills2 & (65536 - (3 * f)) | (self.b_skill * f));
	}

	h = ftos(current_bots);
	cvar_set("scratch1", h);
	h = ftos(saved_skills1);
	cvar_set("scratch2", h);
	h = ftos(saved_skills2);
	cvar_set("scratch3", h);
	self = uself;

};

void(entity bot) BotDisconnect =
{
	local string h;
	local entity uself;
	uself = self;
	self = bot;

	bot_count = bot_count - 1;
	current_bots = current_bots - (current_bots & ClientBitFlag(self.b_num - 1));
	h = ftos(current_bots);
	cvar_set("scratch1", h);


	ClientDisconnect();

	if (self.b_clientno != -1)
	{
      	// the bot's client number is not in use by a real player so we
		// must remove it's entry in the rankings
		// Quake engine sets all fields to 0, can only do the most important here
		self.b_frags = self.frags = 0;
		self.netname = "";
		self.classname = "";
		self.health = 0;
		self.items = 0;
		self.armorvalue = 0;
		self.weaponmodel = "";
		self.b_pants = 0;
		self.b_shirt = 0;
		self.ammo_shells = self.ammo_nails = self.ammo_rockets = self.ammo_cells = 0;
		UpdateClient(self);
		active_clients = active_clients - (active_clients & ClientBitFlag(self.b_clientno));
	      self.b_clientno = -1;
   	}
	self = uself;
};
/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

BotInvalidClientNo
kicks a bot if a player connects and takes the bot's space

-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
*/

void(float clientno) BotInvalidClientNo =
{
	local entity bot;

	bot = GetClientEntity(clientno);
	if(bot.b_clientno > 0)
	{
		if (active_clients & ClientBitFlag(self.b_clientno))
		{
			bot.b_clientno = -1;
			BotDisconnect(bot);
			active_clients = active_clients | ClientBitFlag(self.b_clientno);
			BotConnect(0, bot.b_num, bot.b_skill); 
			return;
		}
	}
};

/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Waypoint Loading from file

-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
*/
void() LoadWaypoint = 
{
	local vector org;
	local entity tep;
	local float r;
	org_x = cvar("saved1");
	org_y = cvar("saved2");
	org_z = cvar("saved3");
	
	tep = make_waypoint(org);

	r = cvar("saved4");

	tep.b_aiflags = floor(r / 4);
	tep.b_pants = cvar("scratch1");
	tep.b_skill = cvar("scratch2");
	tep.b_shirt = cvar("scratch3");
	tep.b_frags = cvar("scratch4");
};

void() bot_return =
{
	if (time > 2)
	{
		if ((waypoint_mode == WM_DYNAMIC) || (waypoint_mode == WM_LOADED))
		{
			// minor precaution

			if (saved_bots & 1) BotConnect(0, 1, saved_skills1 & 3);
			if (saved_bots & 2) BotConnect(0, 2, (saved_skills1 & 12) / 4);
			if (saved_bots & 4) BotConnect(0, 3, (saved_skills1 & 48) / 16);
			if (saved_bots & 8) BotConnect(0, 4, (saved_skills1 & 192) / 64);
			if (saved_bots & 16) BotConnect(0, 5, (saved_skills1 & 768) / 256);
			if (saved_bots & 32) BotConnect(0, 6, (saved_skills1 & 3072) / 1024);
			if (saved_bots & 64) BotConnect(0, 7, (saved_skills1 & 12288) / 4096);
			if (saved_bots & 128) BotConnect(0, 8, (saved_skills1 & 49152) / 16384);
			if (saved_bots & 256) BotConnect(0, 9, saved_skills2 & 3);
			if (saved_bots & 512) BotConnect(0, 10, (saved_skills2 & 12) / 4);
			if (saved_bots & 1024) BotConnect(0, 11, (saved_skills2& 48) / 16);
			if (saved_bots & 2048) BotConnect(0, 12, (saved_skills2 & 192) / 64);
			if (saved_bots & 4096) BotConnect(0, 13, (saved_skills2 & 768) / 256);
			if (saved_bots & 8192) BotConnect(0, 14, (saved_skills2 & 3072) / 1024);
			if (saved_bots & 16384) BotConnect(0, 15, (saved_skills2 & 12288) / 4096);
			if (saved_bots & 32768) BotConnect(0, 16, (saved_skills2 & 49152) / 16384);
			saved_bots = 0;
		}
	}
};


void() WaypointWatch =
{
	// Waypoint Baywatch
	local float bigboobs;
	local string h;
	//if (framecount < 4)
	//	return;
	if (max_clients < 2)
		return;
	if (waypoint_mode != WM_UNINIT)
	{
		bigboobs = cvar("saved4");
		if (bigboobs != 0)
		{
			if ((bigboobs & 3) == 1)
				ClearAllWays();
			else if ((bigboobs & 3) == 3)
			{
				FixWaypoints();
				h = ftos(b_options);
				cvar_set("saved1", h);
				cvar_set("saved4", "0");
				cvar_set("scratch1", "0");
				waypoint_mode = WM_LOADED;
				return;
			}
			LoadWaypoint();
			waypoint_mode = WM_LOADING;
			cvar_set("saved4", "0");
		}
	}
	else
	{
		// the bots return!
		b_options = cvar("saved1");
		if (coop || (b_options & OPT_SAVEBOTS))
		{
			saved_bots = cvar("scratch1");
			saved_skills1 = cvar("scratch2");
			saved_skills2 = cvar("scratch3");
		}
		cvar_set ("saved4", "0");
		if (max_clients > 1)
		{
			localcmd("exec maps/");
			localcmd(mapname);
			localcmd(".way\n");
			waypoint_mode = WM_DYNAMIC;
			bot_map_load();
		}
		else
			waypoint_mode = WM_LOADED;
	}
};
void() BotFrame =
{
	local float num;

	// for the sake of speed
	sv_maxspeed = cvar("sv_maxspeed");
	sv_gravity = cvar("sv_gravity");
	sv_friction = cvar("sv_friction");
	sv_accelerate = cvar("sv_accelerate");
	sv_stopspeed = cvar("sv_stopspeed");
	real_frametime = frametime; // in NQ this is alright
	
	self = nextent(world);
	num = 0;
	while (num < max_clients)
	{
		if (self.ishuman == FALSE)
		{
			if (active_clients & ClientBitFlag(num))
			{
				frik_obstacles();
				CL_KeyMove();
				SV_ClientThink();
				SV_Physics_Client();
			}
		}
		self = nextent(self);
		num = num + 1;
	}
	WaypointWatch();

	if (saved_bots)
		bot_return();
};

/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Bot Impulses. Allows the player to perform bot
related functions.

-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
*/

void() BotImpulses =
{
	local float f;

	if (self.impulse == 100)
	{
		f = cvar("skill");
		BotConnect(CT_SIDE, 0, f);
	}
	else if (self.impulse == 101)
	{
		f = cvar("skill");
		BotConnect(T_SIDE, 0, f);
	}
	else if (self.impulse == 102)
		KickABot();
	else if (self.impulse == 103)
		botcam_u();
	else if (self.impulse == 104)
		bot_way_edit();
	else
		return;

	self.impulse = 0;
};



