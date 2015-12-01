<GameFile>
  <PropertyGroup Name="MainMenuPlayer" Type="Node" ID="c71c6811-5bbb-4f61-8394-8afa9ac5b1e2" Version="2.3.3.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="120" Speed="1.0000">
        <Timeline ActionTag="-1556599309" Property="Position">
          <PointFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="5" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="10" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="90" X="192.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="120" X="240.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1556599309" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="5" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="10" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="90" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="120" X="0.4500" Y="0.4500">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1556599309" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="5" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="10" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="90" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="120" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1556599309" Property="FileData">
          <TextureFrame FrameIndex="0" Tween="False">
            <TextureFile Type="Normal" Path="Resource/Player_EyeOpen_big.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="5" Tween="False">
            <TextureFile Type="Normal" Path="Resource/Player_EyeClose_big.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="10" Tween="False">
            <TextureFile Type="Normal" Path="Resource/Player_EyeOpen_big.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="70" Tween="False">
            <TextureFile Type="Normal" Path="Resource/Player_EyeOpen_big.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="75" Tween="False">
            <TextureFile Type="Normal" Path="Resource/Player_EyeClose_big.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="80" Tween="False">
            <TextureFile Type="Normal" Path="Resource/Player_EyeOpen_big.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="90" Tween="False">
            <TextureFile Type="Normal" Path="Resource/Player_EyeOpen_big.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="120" Tween="False">
            <TextureFile Type="Normal" Path="Resource/Player_EyeOpen_big.png" Plist="" />
          </TextureFrame>
        </Timeline>
        <Timeline ActionTag="-1556599309" Property="Alpha">
          <IntFrame FrameIndex="0" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="5" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="10" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="90" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="120" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="Player_Blink" StartIndex="0" EndIndex="10">
          <RenderColor A="150" R="0" G="0" B="139" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" Tag="71" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="Sprite_Player" ActionTag="-1556599309" Tag="72" IconVisible="False" LeftMargin="-37.5000" RightMargin="-37.5000" TopMargin="-122.0000" ctype="SpriteObjectData">
            <Size X="75.0000" Y="122.0000" />
            <AnchorPoint ScaleX="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Resource/Player_EyeOpen_big.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>