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
      <Item Name="Dependencies" Type="Dependencies"/>
      <Item Name="Build Specifications" Type="Build"/>
   </Item>
</Project>
