<GameFile>
  <PropertyGroup Name="PlayerNode" Type="Node" ID="0392ae04-9872-4fe7-9864-cdf4ca825b16" Version="2.3.3.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="30" Speed="1.0000">
        <Timeline ActionTag="-12689202" Property="Position">
          <PointFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="30" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-12689202" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-12689202" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-12689202" Property="FileData">
          <TextureFrame FrameIndex="0" Tween="False">
            <TextureFile Type="Normal" Path="Resource/Player_EyeOpen.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="15" Tween="False">
            <TextureFile Type="Normal" Path="Resource/Player_EyeClose.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="30" Tween="False">
            <TextureFile Type="Normal" Path="Resource/Player_EyeOpen.png" Plist="" />
          </TextureFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="blink" StartIndex="0" EndIndex="30">
          <RenderColor A="150" R="102" G="205" B="170" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" Tag="126" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="Sprite_Player" ActionTag="-12689202" Tag="128" IconVisible="False" LeftMargin="-16.0000" RightMargin="-16.0000" TopMargin="-52.0000" ctype="SpriteObjectData">
            <Size X="32.0000" Y="52.0000" />
            <Children>
              <AbstractNodeData Name="Sprite_Shield" ActionTag="-1470063485" Tag="116" IconVisible="False" LeftMargin="33.0000" RightMargin="48.0000" TopMargin="160.0000" BottomMargin="-7.0000" FlipX="True" ctype="SpriteObjectData">
                <Size X="53.0000" Y="64.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="33.0000" Y="25.0000" />
                <Scale ScaleX="0.4000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2463" Y="0.1152" />
                <PreSize X="0.3955" Y="0.2949" />
                <FileData Type="Normal" Path="Resource/Item/shield.png" Plist="" />
                <BlendFunc Src="770" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Resource/Player_EyeOpen.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>