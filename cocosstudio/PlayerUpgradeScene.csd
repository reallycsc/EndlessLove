<GameFile>
  <PropertyGroup Name="PlayerUpgradeScene" Type="Scene" ID="037393e8-19b9-4b7e-83a2-fbf8bda2343b" Version="2.3.3.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" Tag="237" ctype="GameNodeObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="Text_Title" ActionTag="797562638" Tag="388" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="363.5000" RightMargin="363.5000" BottomMargin="563.0000" FontSize="60" LabelText="Upgrade" OutlineSize="4" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
            <Size X="233.0000" Y="77.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
            <Position X="480.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="1.0000" />
            <PreSize X="0.2427" Y="0.1203" />
            <FontResource Type="Normal" Path="Font/fzzj.ttf" Plist="" />
            <OutlineColor A="255" R="255" G="165" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Sprite_GuideLine" ActionTag="-358182099" Tag="536" IconVisible="False" LeftMargin="1.0000" RightMargin="1.0000" TopMargin="689.0000" BottomMargin="-51.0000" ctype="SpriteObjectData">
            <Size X="958.0000" Y="2.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="-50.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="-0.0781" />
            <PreSize X="0.9979" Y="0.0031" />
            <FileData Type="Normal" Path="Resource/guideLine.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Node_GoldNumber" ActionTag="-883127292" Tag="347" IconVisible="True" PositionPercentXEnabled="True" LeftMargin="480.0000" RightMargin="480.0000" TopMargin="140.0000" BottomMargin="500.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="Sprite_GoldCoin" ActionTag="-732922275" Tag="348" IconVisible="False" HorizontalEdge="LeftEdge" VerticalEdge="TopEdge" LeftMargin="-87.0000" RightMargin="35.0000" TopMargin="-26.0000" BottomMargin="-26.0000" ctype="SpriteObjectData">
                <Size X="52.0000" Y="52.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="-87.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="MarkedSubImage" Path="Resource/Item/goldCoin.png" Plist="Item.plist" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_GoldNumber" ActionTag="1727732741" Tag="349" IconVisible="False" HorizontalEdge="LeftEdge" VerticalEdge="TopEdge" LeftMargin="-30.0000" RightMargin="-79.0000" TopMargin="-28.5000" BottomMargin="-35.5000" FontSize="54" LabelText="9999" HorizontalAlignmentType="HT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="109.0000" Y="64.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="-30.0000" Y="-3.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="Font/fzzj.ttf" Plist="" />
                <OutlineColor A="255" R="0" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="480.0000" Y="500.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.7813" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="Button_MainMenu" ActionTag="1802285559" Tag="62" IconVisible="False" LeftMargin="20.0000" RightMargin="810.0000" TopMargin="20.0000" BottomMargin="560.0000" TouchEnable="True" FontSize="24" ButtonText="Return" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="130" Scale9Height="38" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="130.0000" Y="60.0000" />
            <AnchorPoint ScaleY="1.0000" />
            <Position X="20.0000" Y="620.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.0208" Y="0.9688" />
            <PreSize X="0.1354" Y="0.0938" />
            <FontResource Type="Normal" Path="Font/fzzj.ttf" Plist="" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="MarkedSubImage" Path="Resource/UI/button_disable.png" Plist="UI.plist" />
            <PressedFileData Type="MarkedSubImage" Path="Resource/UI/button_down.png" Plist="UI.plist" />
            <NormalFileData Type="MarkedSubImage" Path="Resource/UI/button_up.png" Plist="UI.plist" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Panel_ListBack" ActionTag="-1543593252" Tag="2817" IconVisible="False" LeftMargin="270.0000" RightMargin="50.0000" TopMargin="190.0000" BottomMargin="50.0000" TouchEnable="True" ComboBoxIndex="1" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
            <Size X="640.0000" Y="400.0000" />
            <AnchorPoint ScaleX="1.0000" />
            <Position X="910.0000" Y="50.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.9479" Y="0.0781" />
            <PreSize X="0.6667" Y="0.6250" />
            <SingleColor A="255" R="191" G="191" B="191" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="ListView_UpgradeItems" ActionTag="1536581789" Tag="66" IconVisible="False" LeftMargin="275.0000" RightMargin="55.0000" TopMargin="195.0000" BottomMargin="55.0000" TouchEnable="True" ClipAble="True" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" IsBounceEnabled="True" ScrollDirectionType="0" ItemMargin="5" DirectionType="Vertical" ctype="ListViewObjectData">
            <Size X="630.0000" Y="390.0000" />
            <AnchorPoint ScaleX="1.0000" />
            <Position X="905.0000" Y="55.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.9427" Y="0.0859" />
            <PreSize X="0.6563" Y="0.6094" />
            <SingleColor A="255" R="255" G="0" B="0" />
            <FirstColor A="255" R="150" G="150" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>