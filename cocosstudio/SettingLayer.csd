<GameFile>
  <PropertyGroup Name="SettingLayer" Type="Layer" ID="181938f6-92c0-4908-97e9-eebe1e17eee9" Version="2.3.3.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <AnimationList>
        <AnimationInfo Name="Layer_onEnter" StartIndex="0" EndIndex="30">
          <RenderColor A="255" R="210" G="180" B="140" />
        </AnimationInfo>
        <AnimationInfo Name="Layer_onExit" StartIndex="40" EndIndex="70">
          <RenderColor A="255" R="72" G="61" B="139" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Layer" Tag="395" ctype="GameLayerObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="Panel_Setting" ActionTag="-987169673" Tag="416" IconVisible="False" LeftMargin="180.0000" RightMargin="180.0000" TopMargin="95.0000" BottomMargin="95.0000" TouchEnable="True" ClipAble="True" BackColorAlpha="191" ComboBoxIndex="1" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
            <Size X="600.0000" Y="450.0000" />
            <Children>
              <AbstractNodeData Name="Text_Setting" ActionTag="-535048533" Tag="417" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="176.5000" RightMargin="176.5000" BottomMargin="347.0000" FontSize="72" LabelText="Setting" OutlineSize="4" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                <Size X="247.0000" Y="103.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
                <Position X="300.0000" Y="450.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="1.0000" />
                <PreSize X="0.4117" Y="0.2289" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <OutlineColor A="255" R="191" G="191" B="191" />
                <ShadowColor A="255" R="0" G="0" B="0" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_Apply" ActionTag="-1889318832" Tag="423" IconVisible="False" LeftMargin="120.0000" RightMargin="320.0000" TopMargin="350.0000" BottomMargin="40.0000" TouchEnable="True" FontSize="24" ButtonText="OK" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="130" Scale9Height="38" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="160.0000" Y="60.0000" />
                <AnchorPoint ScaleX="0.5000" />
                <Position X="200.0000" Y="40.0000" />
                <Scale ScaleX="0.9815" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.3333" Y="0.0889" />
                <PreSize X="0.2667" Y="0.1333" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Normal" Path="Resource/UI/button_disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Resource/UI/button_down.png" Plist="" />
                <NormalFileData Type="Normal" Path="Resource/UI/button_up.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_Cancel" ActionTag="282631654" Tag="424" IconVisible="False" LeftMargin="320.0000" RightMargin="120.0000" TopMargin="350.0000" BottomMargin="40.0000" TouchEnable="True" FontSize="24" ButtonText="Cancel" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="130" Scale9Height="38" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="160.0000" Y="60.0000" />
                <AnchorPoint ScaleX="0.5000" />
                <Position X="400.0000" Y="40.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.6667" Y="0.0889" />
                <PreSize X="0.2667" Y="0.1333" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Normal" Path="Resource/UI/button_disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Resource/UI/button_down.png" Plist="" />
                <NormalFileData Type="Normal" Path="Resource/UI/button_up.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Node_Chinese" ActionTag="816871038" Tag="187" IconVisible="True" LeftMargin="150.0000" RightMargin="450.0000" TopMargin="190.0000" BottomMargin="260.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="Text" ActionTag="-728670764" Tag="188" IconVisible="False" LeftMargin="20.5000" RightMargin="-119.5000" TopMargin="14.0000" BottomMargin="-46.0000" FontSize="24" LabelText="简体中文" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="99.0000" Y="32.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="70.0000" Y="-30.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="CheckBox" ActionTag="-460261624" Tag="189" IconVisible="False" LeftMargin="-20.0000" RightMargin="-20.0000" TopMargin="-20.0000" BottomMargin="-20.0000" TouchEnable="True" CheckedState="True" ctype="CheckBoxObjectData">
                    <Size X="40.0000" Y="40.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <NormalBackFileData Type="Default" Path="Default/CheckBox_Normal.png" Plist="" />
                    <PressedBackFileData Type="Default" Path="Default/CheckBox_Press.png" Plist="" />
                    <DisableBackFileData Type="Default" Path="Default/CheckBox_Disable.png" Plist="" />
                    <NodeNormalFileData Type="Default" Path="Default/CheckBoxNode_Normal.png" Plist="" />
                    <NodeDisableFileData Type="Default" Path="Default/CheckBoxNode_Disable.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Sprite_Flag" ActionTag="638768843" Tag="190" IconVisible="False" LeftMargin="27.0000" RightMargin="-113.0000" TopMargin="-49.0000" BottomMargin="-9.0000" ctype="SpriteObjectData">
                    <Size X="86.0000" Y="58.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="70.0000" Y="20.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="Resource/Chinese_Flag.png" Plist="" />
                    <BlendFunc Src="770" Dst="771" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="150.0000" Y="260.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2500" Y="0.5778" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="Node_English" ActionTag="-1895475500" Tag="446" IconVisible="True" LeftMargin="350.0000" RightMargin="250.0000" TopMargin="190.0000" BottomMargin="260.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="Text" ActionTag="-1366757121" Tag="450" IconVisible="False" LeftMargin="29.0000" RightMargin="-111.0000" TopMargin="14.0000" BottomMargin="-46.0000" FontSize="24" LabelText="English" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="82.0000" Y="32.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="70.0000" Y="-30.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="CheckBox" ActionTag="-1302668299" Tag="447" IconVisible="False" LeftMargin="-20.0000" RightMargin="-20.0000" TopMargin="-20.0000" BottomMargin="-20.0000" TouchEnable="True" CheckedState="True" ctype="CheckBoxObjectData">
                    <Size X="40.0000" Y="40.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <NormalBackFileData Type="Default" Path="Default/CheckBox_Normal.png" Plist="" />
                    <PressedBackFileData Type="Default" Path="Default/CheckBox_Press.png" Plist="" />
                    <DisableBackFileData Type="Default" Path="Default/CheckBox_Disable.png" Plist="" />
                    <NodeNormalFileData Type="Default" Path="Default/CheckBoxNode_Normal.png" Plist="" />
                    <NodeDisableFileData Type="Default" Path="Default/CheckBoxNode_Disable.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Sprite_Flag" ActionTag="-756222021" Tag="186" IconVisible="False" LeftMargin="27.0000" RightMargin="-113.0000" TopMargin="-49.0000" BottomMargin="-9.0000" ctype="SpriteObjectData">
                    <Size X="86.0000" Y="58.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="70.0000" Y="20.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="Resource/American_Flag.png" Plist="" />
                    <BlendFunc Src="770" Dst="771" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="350.0000" Y="260.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5833" Y="0.5778" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.6250" Y="0.7031" />
            <SingleColor A="255" R="26" G="26" B="26" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>