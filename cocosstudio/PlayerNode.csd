<GameFile>
  <PropertyGroup Name="PlayerNode" Type="Node" ID="0392ae04-9872-4fe7-9864-cdf4ca825b16" Version="2.3.3.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="100" Speed="1.0000">
        <Timeline ActionTag="-1470063485" Property="Position">
          <PointFrame FrameIndex="40" X="35.0000" Y="27.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="70" X="35.0000" Y="27.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="100" X="35.0000" Y="27.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1470063485" Property="Scale">
          <ScaleFrame FrameIndex="40" X="0.5000" Y="0.8500">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="70" X="0.5000" Y="0.8500">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="100" X="0.5000" Y="0.8500">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1470063485" Property="RotationSkew">
          <ScaleFrame FrameIndex="40" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="70" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="100" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1470063485" Property="Alpha">
          <IntFrame FrameIndex="40" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="70" Value="127">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="100" Value="255">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-12689202" Property="Position">
          <PointFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="10" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-12689202" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="10" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-12689202" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="10" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-12689202" Property="FileData">
          <TextureFrame FrameIndex="0" Tween="False">
            <TextureFile Type="Normal" Path="Resource/Player_EyeOpen_smal.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="5" Tween="False">
            <TextureFile Type="Normal" Path="Resource/Player_EyeClose_small.png" Plist="" />
          </TextureFrame>
          <TextureFrame FrameIndex="10" Tween="False">
            <TextureFile Type="Normal" Path="Resource/Player_EyeOpen_smal.png" Plist="" />
          </TextureFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="Player_Blink" StartIndex="0" EndIndex="10">
          <RenderColor A="255" R="102" G="205" B="170" />
        </AnimationInfo>
        <AnimationInfo Name="Shield_Fade" StartIndex="40" EndIndex="100">
          <RenderColor A="255" R="32" G="178" B="170" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" Tag="126" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="Sprite_Player" ActionTag="-12689202" Tag="128" IconVisible="False" LeftMargin="-17.0000" RightMargin="-17.0000" TopMargin="-55.0000" ctype="SpriteObjectData">
            <Size X="34.0000" Y="55.0000" />
            <Children>
              <AbstractNodeData Name="Sprite_Shield" ActionTag="-1470063485" Tag="116" IconVisible="False" LeftMargin="35.0000" RightMargin="-54.0000" TopMargin="-4.0000" BottomMargin="-5.0000" ctype="SpriteObjectData">
                <Size X="53.0000" Y="64.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="35.0000" Y="27.0000" />
                <Scale ScaleX="0.5000" ScaleY="0.8500" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="1.0294" Y="0.4909" />
                <PreSize X="1.5588" Y="1.1636" />
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
            <FileData Type="Normal" Path="Resource/Player_EyeOpen_smal.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>