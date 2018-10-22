<!DOCTYPE html>
<html class=" js mozilla" lang="en"><head>
<title>IITD Webmail :: myfft_module.cpp</title>
<meta name="viewport" content="" id="viewport">
<link rel="shortcut icon" href="https://webmail.iitd.ernet.in/roundcube/skins/larry/images/favicon.ico">
<link rel="stylesheet" type="text/css" href="IITD%20Webmail%20::%20myfft_module_files/styles.css">
<link rel="stylesheet" type="text/css" href="IITD%20Webmail%20::%20myfft_module_files/mail.css">
<!--[if IE 9]><link rel="stylesheet" type="text/css" href="skins/larry/svggradients.min.css?s=1510167107" /><![endif]-->
<link rel="stylesheet" type="text/css" href="IITD%20Webmail%20::%20myfft_module_files/jquery-ui-1.css">
<link rel="stylesheet" type="text/css" href="IITD%20Webmail%20::%20myfft_module_files/libcal.css">
<script type="text/javascript" src="IITD%20Webmail%20::%20myfft_module_files/ui.js"></script>



<meta http-equiv="content-type" content="text/html; charset=UTF-8">
<script src="IITD%20Webmail%20::%20myfft_module_files/jquery.js" type="text/javascript"></script>
<script src="IITD%20Webmail%20::%20myfft_module_files/common.js" type="text/javascript"></script>
<script src="IITD%20Webmail%20::%20myfft_module_files/app.js" type="text/javascript"></script>
<script type="text/javascript">

/*
        @licstart  The following is the entire license notice for the 
        JavaScript code in this page.

        Copyright (C) 2005-2014 The Roundcube Dev Team

        The JavaScript code in this page is free software: you can redistribute
        it and/or modify it under the terms of the GNU General Public License
        as published by the Free Software Foundation, either version 3 of
        the License, or (at your option) any later version.

        The code is distributed WITHOUT ANY WARRANTY; without even the implied
        warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
        See the GNU GPL for more details.

        @licend  The above is the entire license notice
        for the JavaScript code in this page.
*/
var rcmail = new rcube_webmail();
rcmail.set_env({"task":"mail","x_frame_options":"sameorigin","standard_windows":false,"locale":"en_US","cookie_domain":"","cookie_path":"\/","cookie_secure":true,"skin":"larry","extwin":1,"framed":true,"refresh_interval":60,"session_lifetime":600,"action":"get","comm_path":".\/?_task=mail&_framed=1","user_id":"5b812aef0ec06982f41b1e649fa87025","compose_extwin":true,"date_format":"dd-mm-yy","libcal_settings":{"date_format":"dd-MM-yyyy","time_format":"HH:mm","date_short":"d-M","date_long":"d MMM yyyy","dates_long":"d MMM[ yyyy]{ '&mdash;' d MMM yyyy}","first_day":1,"timezone":8,"dst":"0","days":["Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"],"days_short":["Sun","Mon","Tue","Wed","Thu","Fri","Sat"],"months":["January","February","March","April","May","June","July","August","September","October","November","December"],"months_short":["Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"],"today":"Today","mimetypes":["text\/plain","text\/html","text\/xml","image\/jpeg","image\/gif","image\/png","image\/bmp","image\/tiff","application\/x-javascript","application\/pdf","application\/x-shockwave-flash"]},"browser_capabilities":{"pdf":"1","flash":"0","tif":"0"},"mimetype":"text\/plain","mailbox":"INBOX","uid":"5642","part":"2","filename":"myfft_module.cpp","request_token":"2mnxUpnuOizQ2CZn5o006TMDvXTwbFIK"});
rcmail.add_label({"loading":"Loading...","servererror":"Server Error!","connerror":"Connection Error (Failed to reach the server)!","requesttimedout":"Request timed out","refreshing":"Refreshing...","windowopenerror":"The popup window was blocked!","uploadingmany":"Uploading files...","html5_notifier.notification_title":"New E-Mail from [from]","html5_notifier.ok_notifications":"The website already got the permission. Desktop Notifications should work.","html5_notifier.no_notifications":"Your browser does not support Desktop Notifications!","html5_notifier.check_ok":"Your browser settings are correct.","html5_notifier.check_fail":"It was not possible to show a notification, please click \"Configure browser\"!","html5_notifier.check_fail_blocked":"Your browser blocked the notification, please set the permission in the browser settings!","calendar.createfrommail":"Save as event","errortitle":"An error occurred!","toggleadvancedoptions":"Toggle advanced options"});
rcmail.gui_container("topline-left","topline-left");
rcmail.gui_container("topline-center","topline-center");
rcmail.gui_container("topline-right","topline-right");
rcmail.gui_container("toolbar","messagetoolbar");
rcmail.register_button('calendar-create-from-mail', 'rcmbtn100', 'link', 'icon calendarlink active', '', '');
rcmail.register_button('download', 'rcmbtn102', 'link', 'button download', 'button download pressed', '');
rcmail.register_button('print', 'rcmbtn103', 'link', 'button print', 'button print pressed', '');
rcmail.gui_object('messagepartframe', 'messagepartframe');
rcmail.gui_object('message', 'messagestack');
</script>

<script type="text/javascript" src="IITD%20Webmail%20::%20myfft_module_files/html5_notifier.js"></script>
<script type="text/javascript" src="IITD%20Webmail%20::%20myfft_module_files/jquery-ui-1.js"></script>
<script type="text/javascript" src="IITD%20Webmail%20::%20myfft_module_files/libcalendaring.js"></script>
</head>
<body class="extwin noscroll">

<script type="text/javascript">
var UI = new rcube_mail_ui();
</script>

<div id="header">
<div id="topline" role="banner" aria-labelledby="aria-label-topnav">
	<h2 id="aria-label-topnav" class="voice">Window control</h2>
	<div class="topleft">
		
					
						<a href="http://www.cc.iitd.ac.in/" target="_blank" class="support-link" id="supportlink">Get support</a>
			</div>
	
	<div class="topright">
	
			<a class="closelink" onclick="self.close()" id="rcmbtn101" role="button" href="#">Close</a>
		</div>
</div>
<br style="clear:both">
</div>


<div id="mainscreen">

<h1 class="voice">Attachment: myfft_module.cpp</h1>

<h2 id="aria-label-toolbar" class="voice">Application toolbar</h2>
<div id="messagetoolbar" class="toolbar fullwidth" role="toolbar" aria-labelledby="aria-label-toolbar">
	<a class="button download" title="Download" id="rcmbtn102" role="button" tabindex="0" aria-disabled="false" href="#" onclick="return rcmail.command('download','',this,event)">Download</a>
	<a class="button print" title="Print" id="rcmbtn103" role="button" tabindex="0" aria-disabled="false" href="#" onclick="return rcmail.command('print','',this,event)">Print</a>
	
</div>

<div id="mainscreencontent">

<div id="messagepartheader" class="uibox listbox" role="contentinfo" aria-labelledby="aria-label-contentinfo" style="width: 220px;">
	<h2 class="boxtitle" id="aria-label-contentinfo">Properties</h2>
	<div class="scroller">
		<table class="listing"><tbody><tr><td class="title">Name:</td>
<td class="header">myfft_module.cpp</td>
</tr>
<tr><td class="title">Type:</td>
<td class="header">text/plain</td>
</tr>
<tr><td class="title">Size:</td>
<td class="header">~3 KB</td>
</tr>
</tbody>
</table>

	</div>
</div>

<div id="messagepartcontainer" class="uibox" role="main" aria-labelledby="aria-label-messagepart" style="left: 232px;">
	<h2 id="aria-label-messagepart" class="voice">Attachment preview</h2>
	<div class="iframebox">
	<iframe name="messagePartFrame" id="messagepartframe" title="Attachment preview" src="IITD%20Webmail%20::%20myfft_module_files/a.asc" frameborder="0"></iframe>
	</div>
</div>

<div id="mailpartsplitterv" unselectable="on" role="presentation" class="splitter splitter-v" style="left: 223px; top: 0px;"></div></div>
</div>

<div id="messagestack"></div>

<script type="text/javascript">
if (!window.UI) { var UI = new rcube_mail_ui(); }
</script>


<script type="text/javascript">

jQuery.extend(jQuery.ui.dialog.prototype.options.position, {
                using: function(pos) {
                    var me = jQuery(this),
                        offset = me.css(pos).offset(),
                        topOffset = offset.top - 12;
                    if (topOffset < 0)
                        me.css('top', pos.top - topOffset);
                    if (offset.left + me.outerWidth() + 12 > jQuery(window).width())
                        me.css('left', pos.left - 12);
                }
            });
$(document).ready(function(){ 
rcmail.init();
});
</script>


</body></html>