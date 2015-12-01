<GameFile>
  <PropertyGroup Name="ControlLayer" Type="Layer" ID="95e9b956-29e7-40c4-bdf8-4c12912ff814" Version="2.3.3.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="30" Speed="1.0000">
        <Timeline ActionTag="-1743798952" Property="Position">
          <PointFrame FrameIndex="0" X="960.0000" Y="720.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="30" X="960.0000" Y="640.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1743798952" Property="Scale">
          <ScaleFrame FrameIndex="0" X="0.6000" Y="0.6000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="0.6000" Y="0.6000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1743798952" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="Scene_Start" StartIndex="0" EndIndex="30">
          <RenderColor A="255" R="255" G="240" B="245" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Layer" Tag="35" ctype="GameLayerObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="Button_Pause" ActionTag="-1743798952" Tag="38" IconVisible="False" LeftMargin="830.0000" TopMargin="-80.0000" BottomMargin="590.0000" TouchEnable="True" FontSize="24" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="100" Scale9Height="108" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="130.0000" Y="130.0000" />
            <AnchorPoint ScaleX="1.0000" ScaleY="1.0000" />
            <Position X="960.0000" Y="720.0000" />
            <Scale ScaleX="0.6000" ScaleY="0.6000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="1.0000" Y="1.1250" />
            <PreSize X="0.1354" Y="0.2031" />
            <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Normal" Path="Resource/UI/button_Pause_down.png.png" Plist="" />
            <PressedFileData Type="Normal" Path="Resource/UI/button_Pause_down.png.png" Plist="" />
            <NormalFileData Type="Normal" Path="Resource/UI/button_Pause_up.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>