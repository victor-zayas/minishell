# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 12:33:28 by vzaya-s           #+#    #+#              #
#    Updated: 2023/02/23 16:25:24 by vzayas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME #
NAME = minishell

# COMPILATION #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
RM = /bin/rm -rf
LREADLINE_FLAGS = -lreadline -L/Users/$(USER)/.brew/opt/readline/lib/
READLINE = -I/Users/$(USER)/.brew/opt/readline/include/
#LINUX_READLINE = -lreadline -L/usr/lib/x86_64-linux-gnu/

# OBJS #
OBJS = $(SRCS:.c=.o)

# SRC #
SRCS = main.c \
	get_data.c \
	utils_iterator.c \
	tokens.c \
	lexer.c \
	lexer2.c \
	builtings.c \
	pwd.c \
	env.c \
	echo.c \
	exit.c \
	cd.c \
	export_unset.c \
	inter.c \
	pipes.c \
	utils_pipes.c \
	cmd.c \
	utils_cmd.c

# MAKEFILE ART #
# COLORS #
BLACK=\033[0;30m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAG=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
PAPYRUS=\033[38;5;223m
END=\033[0m

define MINISHELL
$(MAG)

███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     
████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     
██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     
██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     
██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗
╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝       

$(END)
endef
export MINISHELL

define JOKIN
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNKNMNkkNMMNOOXNMNOKWMMWNNNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXKWMMKoxx,dWX;,0MMK;;xKMk'lWMWx;lcdWMMX0XMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKONNo,OMMO':d'lNX;,0MMNc';xKc'kWMNc.;.cNMWo'kMMKxKMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0KWMMNo.l0c.kMMk.cx':XX;,0MMM0;.'',dNMMX;,l':XWO,,0MWd.oWMNkkNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWMMM0,cNMMMK,.oc.xWXc'x0,;XX;,0MMMMKx;.xWMMMk'c0c.::;c0WMWd.oWMX:'0MMMWNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMOcxWMMk'cNMMMWx.,o;,oc'oNK;,KX;'0MMMMNXl.xMMMNc'xWx..dKWMMMWd.oWMNl.xMMNdcOO0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXOKWM0',KMWx.oWMMMM0'.kK; 'kNMX;,0X:'0MMMMMWO,;KMWk'cXWd.:XMMMMMWx.oWMWo.dNNO,.',dNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMO'cNMO';KMWl.xWMMMMK,.kNc.lWMMX;,0X:'OMMMMMMWd.;00,,0MNc.lWMMMMMWx.oWMWd.'cc,..l0WMMXOKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0KWMK;,KXc'xWMN:'OMMMMMO'.ON:.oWMMO':XX:'OMMMMMMMk. '',OWMK,.xMMMMMMWx.oWMWd.:OKo.lWMMMWd'dWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXc,OWWd'cl.:XMMK,'0MMMMWd.:XNc.oWMK:'kWNc'OMMWXOxo,,' 'OWMMO.'0MMMMMMWd.oWMWd.oWWx.lWMMMK;,0W0oOWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0,,OWNOc. ;KW0c '0MMMMK,.xWWd.;KO;,kWMNc.ldl:::clkKl.cNMMMx.;KMMMMMMWd.dWMWo.dWMO':XMMXc'xWWo.:xxKMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxoKMMWO,,OWMWO,.;:;;.'OMMMWx.;KMMXc.'.'kWMMX: .cdOXWWMMWo.cNMMWd.;XMMMMMMWd'xWMNl.xMMX:'xXk;,xNMNl.:;'OMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXk0Nx':0MMW0;,OWMMO'.lKNo.dWMMNc.lWMMMNk;..;dKWK,.kWMMMMMMMWo.:NMMWd.;KMMMMMMWo.dWMX:'OMMM0,.,;oKWMMNc.;,,KNxoXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWd.cNWk':KMMM0;,kWMWk,;kX0;,kWMX:.oWMMMMM0,.;''ll.cXMMMMMMMMWo 'OMMXc .kMMMMWNk' :XMX:'0MMMNc.dNMMMMMX;.;':XK,'OMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWo.cNMWo.oWMMM0;,OWMW0l'.;' .cdx,.oWMMMMMK,:KKo' .oWMMMMMMMMNl  ;ONd...;kxoolccl:'lXNc'kMMM0,;KMMMMMMK,.'.,o; .OWKKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNl.lNMMK,,0MMMMO,;KMMMNl ,l'.;l:. :XMMMMNd'oNMWd. 'dXMMMMMMMX;.::,,.:Oc..:xO0XNMNd';kd'cXMK:'kWMMMMMMO. . ,ll''OX::KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNc.lWMMWd.oNMMMWo.dWMMMx.,Kk'cXNx.'OMMNOc'lXMW0,,oc.,kNMMMMMk.'0No..OMK:.cXMMMMMMWk..'..cd;,kWMMMMMMWx.';.dWNc'OK,;KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNWMMMNl.lNMMMX:'kWMMMk.lNMMMO.'0X;,0MXc.l0d:;lOWMNx,;OWWO,.lXMMMK;.oWMO.'0MMK;.oNMMMMMMX:.::'..:KWWWWMMMMX:.lo.oWNc'k0,;XMWNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk:dNMMWd.;KMMMMK:'oKWM0';XMMMK,.xO';KMMO'..;xXWMXk;.,0MMMMKc.:KWK:.cXMMk.'0MMMO..OMMMMMWx':KWXd',llccclllc,.,0O':XX;.cl.:XWk;oNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXNXd':0MMK,.dWMMMMXd;';lc.,0MMMNl.'',kNNNNd..xWWKo;,..xWMMMMMK;.,:'.oXMMWx.,KMMMX:.dWMWXkc,lKMMMWo.'x00Okxd, .kWNc'ol.;c,.'l:;l0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKc:kNO,;OWWO'.dNMMMMMNx' ...kMMNO:.  ';;;;::' ;ko,:xO;,0MMMMMMNl  .:OWMMMWo.:XMMMK, ;ol:::o0WMMMMMK;,0MMMMXo.'kWMMO' ,xNWx..cxKWMWNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0:'xWO,;0MW0;.lXMMMMMM0,';.'xd;;cxkdodkOkd:.  .'dNMX;,0MMMMMWx. 'l0MMMMMX:.oWMMK:..;oxOXWMMMMMMWWXc.xXKOl'.cKWMMMK,.xWMWd.oWMMMMKclXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNWMx.oWWx'cNMMO. ;0MMMMMX:,kk,. 'OWMMMMMMMMM0'   lNMMNl.cdooodo'  'lOMMMMMk.'OMW0,.:0WMMMMMWN0xlc::;...,,,;o0WMMMMM0'.OMMNc'OMMMMM0':XMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNx:co;.,dkO:'kNO:...,0MMMKl'oNMXo..oNMMMMMMWNk;,l' :XMMMx..:odoo;....,xWMMMX:.lNMK;.oNMMMMMW0l,';codxkkkOOKXWMMMMMMMWx.,KMWk'cXMMMMWd.oWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNOdooool:,. '::ckKl.:KXd,;xNMMMWO;.c0Kxollc::l00; .kMMMO'cNMMMMO';:. ;KMMKc.:KMWd.;XMMMMMKl. .lKWMMMMMMMMMMMMMMMMMM0,.dWNx' :XMMMWO,;KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXdccldOXMMNx' ,ONWMMX:.,,;dXMMMMMMM0' .,:odxk0NMWx.  oWMMk.lNMMMM0';Ol'.,ol'.lKMMNl.lNMMMMX:.:xo;;dXMMMMMMMMMMMWWWN0d' ,ol:;lc':KMWk,;OWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0ooddl:;dNMWx.'0MMMMMO. 'OWMMMMMMMNo. .oNMMMMMMMO'   cNMMx.lWMMMM0':XNXx' .l0WMMMWo.cNMMMWd.;KMMXo,:ONNKkdolcc:::;'...,:lokXWWx';dc,cKMMN0dkNMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMXl'.':xOo'lNMX:.oWMMMMk. .;kNMMNXOo;,,.'0MMMMMMM0,.c, :XMMx.lWMMMMk.lNMMWO,.xWMMMMMk.,KMMMK;.dWMMMWk,..'',;clooddc. 'xXNWMMMMMNk'.'lOWMWk:;ckNMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMWX0ko,.,l,,0MWx.,KMMWO;,xx;.;cc;:clx0l.cNMMMMMM0;.oKl ,KMMO';KMMMNc'kMMMMWo.cNMMMMMK;.xWMNo.;KMMMNx;.''.'dXMMMMWO, ,0MMMMMMW0l::okXWMMWd'cKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMXxkXWMXl. .cXMMK;.dWXo,:0WMNOo;..'cdkx,.oNWMMMMK;.oNWd..kXx:..lXMWd'lNMMMMWo..dKNWWWNo.:0O:..dWMMK:.;ONNOc'lXMMWx' .oWMMMMMWx':ONMMMMMM0,;KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMXd;,xNM0' 'OMMMWx.'d:'dNMMMMMMWKkl. .,...,:cxKKc.cXMNo. ',,dOd,;do.'0MMMMMX;   ';:ccc, ..':l;,lkO:.lXMMMMNx,;dxc.';.lWMMMMMO,;KMWWWWWWXo.,xO0Ok0WMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMX:'xKl. .OMMMMNo. .dWMMMMMMMMMMWx.cKK0Okd;....'xOo:,.  'OWMWKc.  .xWMMMNl.,;.lO0000x' ,kWMNOl,. 'odoodxO0kc. .cK0,;KMMMMXc.'cc::ccccc:;:::::cxXMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMXkkKd.',;d;.'xNMMMNo..lXWMMMMMMMMMWd.oWMMMMMNd.  .,:lxKk' ;XWKkl.    .oKXKo.;0k':XMMMMK,.xWMMMMM0, .,coddoc,.. .dNMWo.oWWKd,.'codxkkOO0K0kdlc:::cxNMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMKd:,.  :KMXo'.'lkXWWO:',cloddddxk0k,;KMMMMMMWx.  .dNMMM0' .;;...,c; .c:,,'..OMX:.:0WMNo.:XMMMMMMK,.lXMMWKd:',lo;,xNM0,;ko'.cONMMMMMMMMKl;:lodkO0XWMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO, .kMMMWXd. .':xKNKxlc::::;. .. cNMMMMMWO, ...lXMXk,..  .ckKNO, cNNx'  .xWMk. .;oc.;0MMMMMWKc..kWKx:',oONMMXo,:0K; ..c0WMMWKOxoool,.,dkO0KKKKKWMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMWKdox0k,.oNMMMM0,'oo,..cONMMMMMWWO'.;..dNMMMNx..:0k..:l'..cOd..:ONK; .xWMM0d, .lOl..c'  .oO000Od:.  .ll..;kNMMMMMMW0;,:. ;OWMWKd:;clodddoolc;,'',;;oXMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMW0do:,lx;.:0WMNl.dWMNOl..cKMMMMMWk':Kk'.dNMNo..oNMWO,   ;OWMWO, .'' ..,kNMN0c   .  lXo   ........;l'   .oNMMMMMMMMWNo. 'xNMMNd,;xKWMMMMMNOoc:::;;;;oKMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMWXXXc.c:...ckx',0WNXKOl. ,kXNMWO,;0MWO,.oXO. lNMMMMO' .dWMMMX:     lk:.;k0k; ,,  .xNl .okOkkkkOKXo.   'llc::ccccc:'..c0NNXO:'oXMMMMMN0o:;lkKNNNXKKKWMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMXo:c,.,lOKx,..  ',,,,,;,. ..,ld,'OWMMW0:.,' .OMMMMMK,  .kWXx,  .  .xWNx..''. o0: .dNl.cNMMMMMMNO:.     .',,,,',,'  .':ccc;..oNWXOxl:'..,d0XWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMNK00KNWWXd;,coc'.,xKXNXo .;,.  :XMMMMMNk;  .cxk0KKl.;; ':.  'ok:  oWWO'    .dNd. ;d,.cKXXX0ko,.  ..  c0NWWWWNNk' ;OXXXXKd.,xd:,,;clll:,...;codkOOXWMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMW0dxkkxoc;:dXWMMXd.,kWMM0' oXx. .oXMMMMMWo.  ';;,'. .''    .cKMWk. :Oo..,.   cO:      ......    'dl.  ;OWMMMMNd. .dWMMMMK; ..,lkXWMMMMWNO;.:lc:;;;dNMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMWO:. ..:d0NMMMMMMWo..lXMX: :XW0;  cKMMWKo.   oNXd..lkdl'   :XMMMO.  ..;0Xl.  ..     .,clol,.  'o0k'  ,'.cKWMXl.;:.oWMMMNl..;xXWMMWNKOkxdd;.;xO0XNNWMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMKl:cc,,oXMMMMMMMWd..':0No '0MMK:  ;OOl. .;. ,Ox..dNMMK:   lNMW0:    .OMNl.        .dNNOl'..:x0Oc.  ,0Kc..x0c.:K0;,0MMWd.'kNMMWKdc::ccllolllcc::cxXMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMWKxlc;..'cokXWMNx':00:,lc..OMMMNo. ..  :0Nx. '. :XMNx'    ;Okc. .'. .lkc. .::. .' .dd,.  'cl:'.   ;0WMNo....:KMWk,;0Wk.'OMMMWO;,d0NWN0xddxk0XXOxkNMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMWOcoO0o.;do:;lkl'lXMMNk:. .lKXXXKx;.  .xXWWO;   ;XNo.  ;,  .. 'o0Nx.   .:dOK: .kx. .      ..''. .lXMMMMNc  '0MMMWk.'l'.xWMMMWo.xWWKd;,:oolc::clxXMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMWWMMWd.oWMNk;..cXWMMMMWx. .',,,,,'.    .;coo;.  :o'  .OO.   cXMMXo.   oNMWd. lXx.    ':oxOXXd. ;0NNNNXk,  oWMMMMNl   cXMMMMWo.':,.  .;ldk0K0kdxKMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMWKkdl,.cXMMMKo'.';:cllol. :O00OOOkc.  .               ;dc  .xWNx,...  cKXd. .od.    ;OWMMMMX;  .,'''''....kMMMMMNl   .;:cdxc...,;,. .,;'..':d0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMXdcodo:,;oxdl;....,;;,.   '0MMMMWk'  .lo,  .;lc.        .   ck; .lKx. ....   ..  ;:...;oKWNo. .:oodddk0k'.xWMMMXd. .,..,:,.  'd0NNO'.OWNKko;'cKMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNOol:.   .;cdOKNWWWNKx,  'dO0kc..;, 'ONx' .cx, .:l'          .lNM0'     ;,    cXWKd,  .lc. :0WMMMMMMWx. :00xl,.;xKd'cXWNKkl,..;lo'.kMMMMMWNNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNo'.. ...,ckKWMMMMW0o:;.   .'',ckXo .oXXk,  .  ;KWKc. '.     ;KWKl.   .cXk.  .dWNKOl.     .,okKWMMMWO,   ..  .ckKK:.xXXNWWWN0dc,.  ':loodKMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNKl.cKKk;..;lddo:;cx0Kk; .;d0NWXc  .'..     .kMMMK, :k;    ,c,...  .lOMO'   .:,.  .,:ldo;  .;:lol;. .,cloooc,...  .'.',;cox0XXO,.:c:;;cOWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0clKWKl';okx,...:0WMMMXd.  .';:,,:ol.      ,KMMMO' lNk.    .,okc  ;kXWd.         ,dO0x; .:OKOxc.  ;ONMMMWOc..':lo:.   .,,..';:..oNWWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNKkl;;xNMMNl'dk:,l0WMMWKo.  .l0NWMO. .ol. .kWWO, ;KM0'   .oXKo.  :0Kk'      .:c:'..   .oKXKkl.  .lxkkxl;..lOXKx;. .:xKNNXOdc,. .,lxXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWOloONMMMMWl.xMNOc;cxOxl,.   .,lO0c  lNXc  ,xl..cKMMX;   ;Od'    ,dl.       .;::c;    .'''.   .';::c:'  'kXOl'    .,,;;coxOKXKOdc;:OMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWN0kxdxo'.oOOOd;     .,cc:,.  .  .xWMO.     lNMMMNl   .' .cl.      .,.  .cddc.  .oOxo:.   .cdxxxdl'  .;'     .;loool:,...,cx0XWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNd:cll;..',..  .,.  ,ONMMWNKxc'.  .:ox:    .dWMMMMO.    .xWX;     .lc   ;kkdc.  .;c:'.             .';:::,.  .,cdOKNWNXOxl;..cKMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNNXkl;:ONKc .lKXc .xWXOxoodxkd:.           .cxkkkd'    ;KXl.      ..                  .cdxkd:. .cxKNWMNk:..,;;,'..,:lodxddkO0NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0loONMM0' lNMWo .:c.                                 .:;  .cd;             ',.   .. .;oxd;.'dKWMMMMNo..l0NWWWO,.:c;,''':OWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0; .OMMNc   .:odc.         .,cllc'      ...         ;KWx.    .;l:. .ldc.  ;kd.      :KMMMMMMWd..cOOkO0O:.;kKXNNNNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWOc....cKXl....,0WO'  ;xd' .:,..ck0d'  .:x0KOc.        .:l'     .,,.  ..     .'.';'    .ckKXXXOl. .,;'. .'..:cc:cOWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWOclkXo.,;'c0K:.cd.  '0MWx..:kd,  .   .:xkko'..    'c,        .',,'.        .'cx0Xx.      ..''..';::,. .:c..xNNKOKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNl .c0WMWd.  ...,KMMWO; .dx'            :l.   oWXl       'oo:'.        ..,,,'.  .c:.    .';;'.   ..''. 'OMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXl:OWMMMNo  .xk.'0MMMMK: ..    .'''.   ;x:    'kWK,              'cllc;'.   'co;..lkkc. ..  .,cok0XXX0kkXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNWMWKkd:...,0k.,xxolll'      ,ONNNXk, .'.:o'  .cOc              .;xNMWNKkl,..:dd;..cl.;0O; ,KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXl'';oOo.:; .,col'        cNMWKxc.   'OW0;   ..             .. .:0NWNKkl,.  ;xkc.  ;KWd..dNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNXNWMMO. .'oKWXl.    ,c. ;00c.  ..   ;kx.            ;kl. :O0d' .','..:odl,..lK0; .xWNd..xWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWd.'dXWMXc  :o. lKl .,.   ;xkxc. ..  lx'        cNX: ,KMWk. ,l:..:0WMNx..lXX: ,0MWKOXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKOXWMMXc .dNO'.kWK;      .;:c:'    .kW0,       cNWo  :0WK; cNWKc..xWMWx..xW0'.oWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWo.'kWWo.:XMWx. ,d, ;OXXKx'    lNWd.      cNWo  ..:l' :XMMNo..xWMK,.oWW0d0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKkKWWx':KMMWx..xNd..OMWO;,c.  .lXx.      :XWo 'xx:.  ;KMMMNl.'OMW0xKMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0OXMMMWo '0Mx..kM0,,OX: ...od.      ;XWl .OMWO; .oNMMMXo:kWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWOcdNWx.'ONo.dWO'.c: ;c.      ;XWk. cNMMNx;cKMMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXx0WWkdXWd':Ol'd0l,'...;kWMNxcxNMMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNXNWNXWMWWNXXNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
endef
export JOKIN

# RULES #
.SILENT:

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(READLINE) -c $^ -o $@

$(NAME): $(OBJS)
	make -C libft all
	 $(CC) $(CFLAGS) $(LREADLINE_FLAGS) $(READLINE) libft/libft.a $^ -o $(NAME)
#	$(CC) $(CFLAGS) $^ $(LREADLINE_FLAGS) $(LINUX_READLINE) libft/libft.a -o $(NAME)
	echo "$(BLUE)༺ library created༻$(END)"
	echo "$$MINISHELL"
	echo "Special thanks to $(GREEN)༺ HELECHOS༻$(END)".
ifeq ($(USER), $(filter $(USER), jaizpuru))
		echo $$JOKIN
		osascript -e "set Volume 2"
		say --voice="Luciana" você é uma pessoa maravilhosa e um grande amigo.
endif

clean:
	make -C libft clean
	$(RM) $(OBJS)
		echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)
		echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re
