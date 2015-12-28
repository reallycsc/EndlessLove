<GameFile>
  <PropertyGroup Name="NormalNoticeLayer" Type="Layer" ID="94c9dcdf-4962-435b-a2e9-6852c338e3c7" Version="2.3.3.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Layer" Tag="112" ctype="GameLayerObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="Panel_Background" ActionTag="-1292871657" Tag="305" IconVisible="False" LeftMargin="230.0000" RightMargin="230.0000" TopMargin="170.0000" BottomMargin="170.0000" TouchEnable="True" ComboBoxIndex="2" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
            <Size X="500.0000" Y="300.0000" />
            <Children>
              <AbstractNodeData Name="Text_Title" ActionTag="1175532923" Tag="138" IconVisible="False" HorizontalEdge="BothEdge" VerticalEdge="BothEdge" LeftMargin="141.0000" RightMargin="141.0000" BottomMargin="243.0000" FontSize="40" LabelText="Notifaction" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                <Size X="218.0000" Y="57.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
                <Position X="250.0000" Y="300.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="165" B="0" />
                <PrePosition X="0.5000" Y="1.0000" />
                <PreSize X="0.4360" Y="0.1900" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <OutlineColor A="255" R="0" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="ScrollView_info" ActionTag="766522846" Tag="32" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="20.0000" RightMargin="20.0000" TopMargin="80.0000" BottomMargin="100.0000" TouchEnable="True" ClipAble="True" BackColorAlpha="102" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" IsBounceEnabled="True" ScrollDirectionType="Vertical" ctype="ScrollViewObjectData">
                <Size X="460.0000" Y="120.0000" />
                <Children>
                  <AbstractNodeData Name="Text_info" ActionTag="-1050109559" Tag="315" IconVisible="False" PositionPercentYEnabled="True" HorizontalEdge="BothEdge" RightMargin="253.0000" BottomMargin="88.0000" FontSize="24" LabelText="Not enough gold!" OutlineSize="2" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="207.0000" Y="32.0000" />
                    <AnchorPoint ScaleY="1.0000" />
                    <Position Y="120.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition Y="1.0000" />
                    <PreSize X="0.4500" Y="0.2667" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="0" G="0" B="0" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
                <Position X="250.0000" Y="220.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.7333" />
                <PreSize X="0.9200" Y="0.4000" />
                <SingleColor A="255" R="255" G="150" B="100" />
                <FirstColor A="255" R="255" G="150" B="100" />
                <EndColor A="255" R="255" G="255" B="255" />
                <ColorVector ScaleY="1.0000" />
                <InnerNodeSize Width="460" Height="120" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_OK" ActionTag="-1131707983" Tag="320" IconVisible="False" HorizontalEdge="BothEdge" VerticalEdge="BothEdge" LeftMargin="170.0000" RightMargin="170.0000" TopMargin="210.0000" BottomMargin="30.0000" TouchEnable="True" FontSize="24" ButtonText="OK" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="130" Scale9Height="38" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="160.0000" Y="60.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="250.0000" Y="60.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.2000" />
                <PreSize X="0.3200" Y="0.2000" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="MarkedSubImage" Path="Resource/UI/button_disable.png" Plist="UI.plist" />
                <PressedFileData Type="MarkedSubImage" Path="Resource/UI/button_down.png" Plist="UI.plist" />
                <NormalFileData Type="MarkedSubImage" Path="Resource/UI/button_up.png" Plist="UI.plist" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.5208" Y="0.4688" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="77" G="77" B="77" />
            <EndColor A="255" R="191" G="191" B="191" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>