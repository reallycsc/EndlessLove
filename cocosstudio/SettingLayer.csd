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
          <AbstractNodeData Name="Panel_Setting" ActionTag="-987169673" Tag="416" IconVisible="False" LeftMargin="180.0000" RightMargin="180.0000" TopMargin="20.0000" BottomMargin="20.0000" TouchEnable="True" ClipAble="True" BackColorAlpha="191" ComboBoxIndex="1" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
            <Size X="600.0000" Y="600.0000" />
            <Children>
              <AbstractNodeData Name="Node_Music" ActionTag="893812561" Tag="98" IconVisible="True" PositionPercentXEnabled="True" LeftMargin="348.0000" RightMargin="252.0000" TopMargin="300.0000" BottomMargin="300.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="Button_musicOff" ActionTag="-323765707" Tag="99" IconVisible="False" LeftMargin="-245.0000" RightMargin="115.0000" TopMargin="-65.0000" BottomMargin="-65.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="100" Scale9Height="108" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="130.0000" Y="130.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="-180.0000" />
                    <Scale ScaleX="0.6000" ScaleY="0.6000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="MarkedSubImage" Path="Resource/UI/button_MusicOff_disable.png" Plist="UI.plist" />
                    <PressedFileData Type="MarkedSubImage" Path="Resource/UI/button_MusicOff_down.png" Plist="UI.plist" />
                    <NormalFileData Type="MarkedSubImage" Path="Resource/UI/button_MusicOff_up.png" Plist="UI.plist" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Slider_music" ActionTag="-583236279" Tag="96" IconVisible="False" LeftMargin="-125.0000" RightMargin="-125.0000" TopMargin="-10.0000" BottomMargin="-10.0000" TouchEnable="True" PercentInfo="50" ctype="SliderObjectData">
                    <Size X="250.0000" Y="20.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="85" G="189" B="239" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <BackGroundData Type="Default" Path="Default/Slider_Back.png" Plist="" />
                    <ProgressBarData Type="Default" Path="Default/Slider_PressBar.png" Plist="" />
                    <BallNormalData Type="Default" Path="Default/SliderNode_Normal.png" Plist="" />
                    <BallPressedData Type="Default" Path="Default/SliderNode_Press.png" Plist="" />
                    <BallDisabledData Type="Default" Path="Default/SliderNode_Disable.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Button_musicOn" ActionTag="-1039984682" Tag="100" IconVisible="False" LeftMargin="-245.0000" RightMargin="115.0000" TopMargin="-65.0000" BottomMargin="-65.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="100" Scale9Height="108" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="130.0000" Y="130.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="-180.0000" />
                    <Scale ScaleX="0.6000" ScaleY="0.6000" />
                    <CColor A="255" R="127" G="127" B="127" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="MarkedSubImage" Path="Resource/UI/button_Music_disable.png" Plist="UI.plist" />
                    <PressedFileData Type="MarkedSubImage" Path="Resource/UI/button_Music_down.png" Plist="UI.plist" />
                    <NormalFileData Type="MarkedSubImage" Path="Resource/UI/button_Music_up.png" Plist="UI.plist" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="348.0000" Y="300.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5800" Y="0.5000" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_Setting" ActionTag="-535048533" Tag="417" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="183.5000" RightMargin="183.5000" BottomMargin="509.0000" FontSize="72" LabelText="Setting" OutlineSize="4" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                <Size X="233.0000" Y="91.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
                <Position X="300.0000" Y="600.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="1.0000" />
                <PreSize X="0.3883" Y="0.1517" />
                <FontResource Type="Normal" Path="Font/fzzj.ttf" Plist="" />
                <OutlineColor A="255" R="191" G="191" B="191" />
                <ShadowColor A="255" R="0" G="0" B="0" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_RestorePurcahse" ActionTag="465707624" Tag="85" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="185.0000" RightMargin="185.0000" TopMargin="420.0000" BottomMargin="120.0000" TouchEnable="True" FontSize="24" ButtonText="Restore Purchase" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="130" Scale9Height="38" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="230.0000" Y="60.0000" />
                <AnchorPoint ScaleX="0.5000" />
                <Position X="300.0000" Y="120.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.2000" />
                <PreSize X="0.3833" Y="0.1000" />
                <FontResource Type="Normal" Path="Font/fzzj.ttf" Plist="" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="MarkedSubImage" Path="Resource/UI/button_orange_down.png" Plist="UI.plist" />
                <PressedFileData Type="MarkedSubImage" Path="Resource/UI/button_orange_down.png" Plist="UI.plist" />
                <NormalFileData Type="MarkedSubImage" Path="Resource/UI/button_orange_up.png" Plist="UI.plist" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_Apply" ActionTag="-1889318832" Tag="423" IconVisible="False" LeftMargin="120.0000" RightMargin="320.0000" TopMargin="500.0000" BottomMargin="40.0000" TouchEnable="True" FontSize="24" ButtonText="OK" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="130" Scale9Height="38" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="160.0000" Y="60.0000" />
                <AnchorPoint ScaleX="0.5000" />
                <Position X="200.0000" Y="40.0000" />
                <Scale ScaleX="0.9815" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.3333" Y="0.0667" />
                <PreSize X="0.2667" Y="0.1000" />
                <FontResource Type="Normal" Path="Font/fzzj.ttf" Plist="" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="MarkedSubImage" Path="Resource/UI/button_disable.png" Plist="UI.plist" />
                <PressedFileData Type="MarkedSubImage" Path="Resource/UI/button_down.png" Plist="UI.plist" />
                <NormalFileData Type="MarkedSubImage" Path="Resource/UI/button_up.png" Plist="UI.plist" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Button_Cancel" ActionTag="282631654" Tag="424" IconVisible="False" LeftMargin="320.0000" RightMargin="120.0000" TopMargin="500.0000" BottomMargin="40.0000" TouchEnable="True" FontSize="24" ButtonText="Cancel" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="130" Scale9Height="38" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="160.0000" Y="60.0000" />
                <AnchorPoint ScaleX="0.5000" />
                <Position X="400.0000" Y="40.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.6667" Y="0.0667" />
                <PreSize X="0.2667" Y="0.1000" />
                <FontResource Type="Normal" Path="Font/fzzj.ttf" Plist="" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="MarkedSubImage" Path="Resource/UI/button_disable.png" Plist="UI.plist" />
                <PressedFileData Type="MarkedSubImage" Path="Resource/UI/button_down.png" Plist="UI.plist" />
                <NormalFileData Type="MarkedSubImage" Path="Resource/UI/button_up.png" Plist="UI.plist" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Node_Chinese" ActionTag="816871038" Tag="187" IconVisible="True" LeftMargin="150.0000" RightMargin="450.0000" TopMargin="200.0000" BottomMargin="400.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="Text" ActionTag="-728670764" Tag="188" IconVisible="False" LeftMargin="21.5000" RightMargin="-118.5000" TopMargin="16.0000" BottomMargin="-44.0000" FontSize="24" LabelText="简体中文" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="97.0000" Y="28.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="70.0000" Y="-30.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="Font/fzzj.ttf" Plist="" />
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
                <Position X="150.0000" Y="400.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2500" Y="0.6667" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="Node_English" ActionTag="-1895475500" Tag="446" IconVisible="True" LeftMargin="350.0000" RightMargin="250.0000" TopMargin="200.0000" BottomMargin="400.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="Text" ActionTag="-1366757121" Tag="450" IconVisible="False" LeftMargin="29.5000" RightMargin="-110.5000" TopMargin="16.0000" BottomMargin="-44.0000" FontSize="24" LabelText="English" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="81.0000" Y="28.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="70.0000" Y="-30.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="Font/fzzj.ttf" Plist="" />
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
                <Position X="350.0000" Y="400.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5833" Y="0.6667" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.6250" Y="0.9375" />
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