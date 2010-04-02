<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="8608001">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Support" Type="Folder">
			<Item Name="Draw Ellipse Poly.vi" Type="VI" URL="../Draw Ellipse Poly.vi"/>
			<Item Name="Parse Digital Module.vi" Type="VI" URL="../Parse Digital Module.vi"/>
			<Item Name="Update Battery Indicator.vi" Type="VI" URL="../Update Battery Indicator.vi"/>
			<Item Name="Save DB Images.vi" Type="VI" URL="../Save DB Images.vi"/>
			<Item Name="Receive DS Packet.vi" Type="VI" URL="../Receive DS Packet.vi"/>
			<Item Name="App EXE.ico" Type="Document" URL="../App EXE.ico"/>
			<Item Name="Decode Status Byte.vi" Type="VI" URL="../Decode Status Byte.vi"/>
			<Item Name="deleteoldlogs.vi" Type="VI" URL="../deleteoldlogs.vi"/>
			<Item Name="FTPfiles.vi" Type="VI" URL="../FTPfiles.vi"/>
		</Item>
		<Item Name="TypeDefs" Type="Folder">
			<Item Name="DStoPCPacketTypeDef.ctl" Type="VI" URL="../DStoPCPacketTypeDef.ctl"/>
		</Item>
		<Item Name="Dashboard Main.vi" Type="VI" URL="../Dashboard Main.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="IMAQ Create" Type="VI" URL="/&lt;vilib&gt;/Vision/Basics.llb/IMAQ Create"/>
				<Item Name="IMAQ Image.ctl" Type="VI" URL="/&lt;vilib&gt;/vision/Image Controls.llb/IMAQ Image.ctl"/>
				<Item Name="Image Type" Type="VI" URL="/&lt;vilib&gt;/vision/Image Controls.llb/Image Type"/>
				<Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
				<Item Name="IMAQ Write File 2" Type="VI" URL="/&lt;vilib&gt;/Vision/Files.llb/IMAQ Write File 2"/>
				<Item Name="IMAQ Write BMP File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write BMP File 2"/>
				<Item Name="IMAQ Write Image And Vision Info File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write Image And Vision Info File 2"/>
				<Item Name="IMAQ Write JPEG File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write JPEG File 2"/>
				<Item Name="IMAQ Write JPEG2000 File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write JPEG2000 File 2"/>
				<Item Name="IMAQ Write PNG File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write PNG File 2"/>
				<Item Name="IMAQ Write TIFF File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write TIFF File 2"/>
				<Item Name="Dflt Data Dir.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Dflt Data Dir.vi"/>
				<Item Name="DriverStation.lvlib" Type="Library" URL="/&lt;vilib&gt;/Robotics Library/WPI/DriverStation/DriverStation.lvlib"/>
				<Item Name="Camera.lvlib" Type="Library" URL="/&lt;vilib&gt;/Robotics Library/WPI/Camera/Camera.lvlib"/>
				<Item Name="IMAQ Clear Overlay" Type="VI" URL="/&lt;vilib&gt;/Vision/Overlay.llb/IMAQ Clear Overlay"/>
				<Item Name="IMAQ Overlay Multiple Lines" Type="VI" URL="/&lt;vilib&gt;/Vision/Overlay.llb/IMAQ Overlay Multiple Lines"/>
				<Item Name="Color to RGB.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/colorconv.llb/Color to RGB.vi"/>
				<Item Name="IMAQ GetImageInfo" Type="VI" URL="/&lt;vilib&gt;/Vision/Basics.llb/IMAQ GetImageInfo"/>
				<Item Name="Image Unit" Type="VI" URL="/&lt;vilib&gt;/vision/Image Controls.llb/Image Unit"/>
				<Item Name="IMAQ Overlay Line" Type="VI" URL="/&lt;vilib&gt;/Vision/Overlay.llb/IMAQ Overlay Line"/>
				<Item Name="NI_FPGA_Interface.lvlib" Type="Library" URL="/&lt;vilib&gt;/Robotics Library/NIFPGAInterface/NI_FPGA_Interface.lvlib"/>
				<Item Name="StatusErrorCache.ctl" Type="VI" URL="/&lt;vilib&gt;/Robotics Library/WPI/DriverStation/StatusErrorCache.ctl"/>
				<Item Name="NI_InternetTK_FTP_VIs.lvlib" Type="Library" URL="/&lt;vilib&gt;/addons/internet/NI_InternetTK_FTP_VIs.lvlib"/>
				<Item Name="Semaphore RefNum" Type="VI" URL="/&lt;vilib&gt;/Utility/semaphor.llb/Semaphore RefNum"/>
				<Item Name="FTP Session Data.ctl" Type="VI" URL="/&lt;vilib&gt;/addons/internet/ftp/ftp0.llb/FTP Session Data.ctl"/>
				<Item Name="FTP Session.ctl" Type="VI" URL="/&lt;vilib&gt;/addons/internet/ftp/ftp0.llb/FTP Session.ctl"/>
				<Item Name="Close Panel.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/victl.llb/Close Panel.vi"/>
				<Item Name="Open Panel.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/victl.llb/Open Panel.vi"/>
				<Item Name="FTP Status" Type="VI" URL="/&lt;vilib&gt;/addons/internet/ftp/ftp2.llb/FTP Status"/>
				<Item Name="NI_InternetTK_Common_VIs.lvlib" Type="Library" URL="/&lt;vilib&gt;/addons/internet/NI_InternetTK_Common_VIs.lvlib"/>
				<Item Name="Semaphore Name &amp; Ref DB Action.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/semaphor.llb/Semaphore Name &amp; Ref DB Action.ctl"/>
				<Item Name="Semaphore Refnum Core.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/semaphor.llb/Semaphore Refnum Core.ctl"/>
				<Item Name="Not A Semaphore.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/semaphor.llb/Not A Semaphore.vi"/>
				<Item Name="Semaphore Name &amp; Ref DB.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/semaphor.llb/Semaphore Name &amp; Ref DB.vi"/>
				<Item Name="whitespace.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/whitespace.ctl"/>
				<Item Name="Trim Whitespace.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Trim Whitespace.vi"/>
				<Item Name="Error Cluster From Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Cluster From Error Code.vi"/>
				<Item Name="GetNamedSemaphorePrefix.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/semaphor.llb/GetNamedSemaphorePrefix.vi"/>
				<Item Name="RemoveNamedSemaphorePrefix.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/semaphor.llb/RemoveNamedSemaphorePrefix.vi"/>
				<Item Name="Release Semaphore Reference.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/semaphor.llb/Release Semaphore Reference.vi"/>
				<Item Name="Destroy Semaphore.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/semaphor.llb/Destroy Semaphore.vi"/>
				<Item Name="Validate Semaphore Size.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/semaphor.llb/Validate Semaphore Size.vi"/>
				<Item Name="AddNamedSemaphorePrefix.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/semaphor.llb/AddNamedSemaphorePrefix.vi"/>
				<Item Name="Obtain Semaphore Reference.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/semaphor.llb/Obtain Semaphore Reference.vi"/>
				<Item Name="Merge Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Merge Errors.vi"/>
				<Item Name="Get Semaphore Status.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/semaphor.llb/Get Semaphore Status.vi"/>
				<Item Name="Create Semaphore.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/semaphor.llb/Create Semaphore.vi"/>
				<Item Name="compatReadText.vi" Type="VI" URL="/&lt;vilib&gt;/_oldvers/_oldvers.llb/compatReadText.vi"/>
				<Item Name="Case Matching.ctl" Type="VI" URL="/&lt;vilib&gt;/addons/internet/utils/strutil.llb/Case Matching.ctl"/>
				<Item Name="Keyed Array.ctl" Type="VI" URL="/&lt;vilib&gt;/addons/internet/utils/keyedarr.llb/Keyed Array.ctl"/>
				<Item Name="Acquire Semaphore.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/semaphor.llb/Acquire Semaphore.vi"/>
				<Item Name="Release Semaphore.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/semaphor.llb/Release Semaphore.vi"/>
				<Item Name="FTP Type.ctl" Type="VI" URL="/&lt;vilib&gt;/addons/internet/ftp/ftp0.llb/FTP Type.ctl"/>
				<Item Name="compatFileDialog.vi" Type="VI" URL="/&lt;vilib&gt;/_oldvers/_oldvers.llb/compatFileDialog.vi"/>
				<Item Name="compatCalcOffset.vi" Type="VI" URL="/&lt;vilib&gt;/_oldvers/_oldvers.llb/compatCalcOffset.vi"/>
				<Item Name="compatWriteText.vi" Type="VI" URL="/&lt;vilib&gt;/_oldvers/_oldvers.llb/compatWriteText.vi"/>
				<Item Name="FTP File Info.ctl" Type="VI" URL="/&lt;vilib&gt;/addons/internet/ftp/ftp2.llb/FTP File Info.ctl"/>
				<Item Name="Get File Extension.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/libraryn.llb/Get File Extension.vi"/>
			</Item>
			<Item Name="nivissvc.dll" Type="Document" URL="nivissvc.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
			<Item Name="nivision.dll" Type="Document" URL="nivision.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
		</Item>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="FRC PC Dashboard" Type="EXE">
				<Property Name="App_applicationGUID" Type="Str">{AEE2EF3D-7087-47D6-AEAE-9F87F896ED5E}</Property>
				<Property Name="App_applicationName" Type="Str">Dashboard.exe</Property>
				<Property Name="App_fileDescription" Type="Str">FRC PC Dashboard</Property>
				<Property Name="App_fileVersion.major" Type="Int">1</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{47BAFDCE-3F99-4134-9347-62A4C9A5434C}</Property>
				<Property Name="App_INI_GUID" Type="Str">{76D91052-50F0-4E0B-B76F-616DDC550CED}</Property>
				<Property Name="App_internalName" Type="Str">FRC PC Dashboard</Property>
				<Property Name="Bld_buildSpecDescription" Type="Str">Build Dashboard Main.vi into an EXE that will respond to the driver station and display robot information on a PC.</Property>
				<Property Name="Bld_buildSpecName" Type="Str">FRC PC Dashboard</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../NI_AB_PROJECTNAME/build/internal.llb</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../NI_AB_PROJECTNAME/build/data</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Exe_iconItemID" Type="Ref">/My Computer/Support/App EXE.ico</Property>
				<Property Name="Source[0].itemID" Type="Str">{707E3259-8328-41F8-8A6E-50B54BB89A23}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
			</Item>
		</Item>
	</Item>
</Project>
