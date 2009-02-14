<?xml version='1.0'?>
<Project Type="Project" LVVersion="8508002">
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
      <Item Name="Helper VIs" Type="Folder">
         <Item Name="DStoPCPacketTypeDef.ctl" Type="VI" URL="DStoPCPacketTypeDef.ctl"/>
         <Item Name="Update Battery Indicator.vi" Type="VI" URL="Update Battery Indicator.vi"/>
         <Item Name="Decode Status Byte.vi" Type="VI" URL="Decode Status Byte.vi"/>
         <Item Name="Parse Digital Module.vi" Type="VI" URL="Parse Digital Module.vi"/>
         <Item Name="Receive DS Packet.vi" Type="VI" URL="Receive DS Packet.vi"/>
      </Item>
      <Item Name="Dashboard Main.vi" Type="VI" URL="Dashboard Main.vi"/>
      <Item Name="outputvals.vi" Type="VI" URL="outputvals.vi"/>
      <Item Name="Dependencies" Type="Dependencies">
         <Item Name="vi.lib" Type="Folder">
            <Item Name="DriverStation.lvlib" Type="Library" URL="/&lt;vilib&gt;/Robotics Library/WPI/DriverStation/DriverStation.lvlib"/>
            <Item Name="Dflt Data Dir.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Dflt Data Dir.vi"/>
            <Item Name="IMAQ Image.ctl" Type="VI" URL="/&lt;vilib&gt;/vision/Image Controls.llb/IMAQ Image.ctl"/>
            <Item Name="StatusErrorCache.ctl" Type="VI" URL="/&lt;vilib&gt;/Robotics Library/WPI/DriverStation/StatusErrorCache.ctl"/>
            <Item Name="NI_FPGA_Interface.lvlib" Type="Library" URL="/&lt;vilib&gt;/Robotics Library/NIFPGAInterface/NI_FPGA_Interface.lvlib"/>
            <Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
            <Item Name="Camera.lvlib" Type="Library" URL="/&lt;vilib&gt;/Robotics Library/WPI/Camera/Camera.lvlib"/>
            <Item Name="Image Type" Type="VI" URL="/&lt;vilib&gt;/vision/Image Controls.llb/Image Type"/>
            <Item Name="IMAQ Create" Type="VI" URL="/&lt;vilib&gt;/Vision/Basics.llb/IMAQ Create"/>
         </Item>
         <Item Name="Open Log File.vi" Type="VI" URL="Open Log File.vi"/>
         <Item Name="Close Log File.vi" Type="VI" URL="Close Log File.vi"/>
         <Item Name="nivissvc.dll" Type="Document" URL="nivissvc.dll"/>
      </Item>
      <Item Name="Build Specifications" Type="Build"/>
   </Item>
</Project>
