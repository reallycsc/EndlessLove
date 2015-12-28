<GameFile>
  <PropertyGroup Name="PlayerLayer" Type="Layer" ID="8048b8b5-3fa4-4973-9a41-691d0c5f7562" Version="2.3.3.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="30" Speed="1.0000">
        <Timeline ActionTag="1025794162" Property="Position">
          <PointFrame FrameIndex="0" X="-100.0000" Y="530.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="30" X="0.0000" Y="530.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="1025794162" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="1025794162" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-102351201" Property="Position">
          <PointFrame FrameIndex="0" X="480.0000" Y="720.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="30" X="480.0000" Y="640.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-102351201" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-102351201" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="635736572" Property="Position">
          <PointFrame FrameIndex="0" X="0.0000" Y="60.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="30" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="635736572" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="635736572" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="1286181810" Property="Position">
          <PointFrame FrameIndex="0" X="-220.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="30" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="1286181810" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="1286181810" Property="RotationSkew">
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
          <RenderColor A="255" R="255" G="250" B="205" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Layer" Tag="64" ctype="GameLayerObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="Sprite_GuideLine" ActionTag="-1793626092" Tag="79" IconVisible="False" LeftMargin="571.0000" RightMargin="-569.0000" TopMargin="689.0000" BottomMargin="-51.0000" ctype="SpriteObjectData">
            <Size X="958.0000" Y="2.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1050.0000" Y="-50.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="1.0938" Y="-0.0781" />
            <PreSize X="0.9979" Y="0.0031" />
            <FileData Type="Normal" Path="Resource/guideLine.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Node_Player" ActionTag="982365389" Tag="126" IconVisible="True" RightMargin="960.0000" TopMargin="640.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="Node_Heart" ActionTag="-561847720" Tag="120" IconVisible="True" TopMargin="70.0000" BottomMargin="-70.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="Sprite_Heart" ActionTag="-1005586582" Tag="121" IconVisible="False" LeftMargin="-58.0000" TopMargin="-27.5000" BottomMargin="-27.5000" ctype="SpriteObjectData">
                    <Size X="58.0000" Y="55.0000" />
                    <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                    <Position />
                    <Scale ScaleX="0.6000" ScaleY="0.6000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="MarkedSubImage" Path="Resource/Item/Heart.png" Plist="Item.plist" />
                    <BlendFunc Src="770" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_HeartNumber" ActionTag="139768774" Tag="122" IconVisible="False" RightMargin="-23.0000" TopMargin="-15.5000" BottomMargin="-15.5000" FontSize="26" LabelText="-1" HorizontalAlignmentType="HT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="23.0000" Y="31.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <OutlineColor A="255" R="0" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position Y="-70.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_Good" ActionTag="296069100" Tag="123" IconVisible="False" LeftMargin="-43.0000" RightMargin="-43.0000" TopMargin="97.0000" BottomMargin="-143.0000" FontSize="32" LabelText="Good" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                <Size X="86.0000" Y="46.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="-120.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <OutlineColor A="255" R="30" G="144" B="255" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_Great" ActionTag="-1405362863" Tag="124" IconVisible="False" LeftMargin="-44.0000" RightMargin="-44.0000" TopMargin="147.0000" BottomMargin="-193.0000" FontSize="32" LabelText="Great" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                <Size X="88.0000" Y="46.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="-170.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <OutlineColor A="255" R="128" G="0" B="128" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_Perfect" ActionTag="1583817938" Tag="125" IconVisible="False" LeftMargin="-55.5000" RightMargin="-55.5000" TopMargin="197.0000" BottomMargin="-243.0000" FontSize="32" LabelText="Perfect" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                <Size X="111.0000" Y="46.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="-220.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <OutlineColor A="255" R="255" G="165" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="Node_GoldNumber" ActionTag="1025794162" Tag="28" IconVisible="True" VerticalEdge="TopEdge" LeftMargin="-100.0000" RightMargin="1060.0000" TopMargin="110.0000" BottomMargin="530.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="Sprite_GoldCoin" ActionTag="-1661813811" Tag="29" IconVisible="False" LeftMargin="10.0000" RightMargin="-62.0000" TopMargin="-26.0000" BottomMargin="-26.0000" ctype="SpriteObjectData">
                <Size X="52.0000" Y="52.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="10.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="MarkedSubImage" Path="Resource/Item/goldCoin.png" Plist="Item.plist" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_GoldNumber" ActionTag="1494759146" Tag="30" IconVisible="False" LeftMargin="70.0000" RightMargin="-94.0000" TopMargin="-25.0000" BottomMargin="-25.0000" FontSize="36" LabelText="0" HorizontalAlignmentType="HT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="24.0000" Y="50.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="70.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                <OutlineColor A="255" R="0" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="-100.0000" Y="530.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="-0.1042" Y="0.8281" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="Text_Score" ActionTag="-102351201" Tag="34" IconVisible="False" VerticalEdge="TopEdge" LeftMargin="463.5000" RightMargin="463.5000" TopMargin="-80.0000" BottomMargin="646.0000" FontSize="56" LabelText="0" HorizontalAlignmentType="HT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="33.0000" Y="74.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
            <Position X="480.0000" Y="720.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="0" G="0" B="0" />
            <PrePosition X="0.5000" Y="1.1250" />
            <PreSize X="0.0344" Y="0.1156" />
            <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
            <OutlineColor A="255" R="0" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Node_MaxHeart" ActionTag="635736572" Tag="476" IconVisible="True" RightMargin="960.0000" TopMargin="580.0000" BottomMargin="60.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="Sprite_HeartGrey" ActionTag="-1055608885" Tag="45" IconVisible="False" HorizontalEdge="LeftEdge" VerticalEdge="TopEdge" LeftMargin="-60.0000" RightMargin="2.0000" BottomMargin="-55.0000" ctype="SpriteObjectData">
                <Size X="58.0000" Y="55.0000" />
                <AnchorPoint ScaleY="1.0000" />
                <Position X="-60.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="MarkedSubImage" Path="Resource/UI/heart_grey.png" Plist="UI.plist" />
                <BlendFunc Src="770" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="Sprite_HeartLeftGrey" ActionTag="1693082697" Tag="77" IconVisible="False" LeftMargin="-240.0000" RightMargin="208.0000" BottomMargin="-55.0000" ctype="SpriteObjectData">
                <Size X="32.0000" Y="55.0000" />
                <AnchorPoint ScaleY="1.0000" />
                <Position X="-240.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="MarkedSubImage" Path="Resource/UI/heart_left_grey.png" Plist="UI.plist" />
                <BlendFunc Src="770" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="Sprite_Heart" ActionTag="892188995" Tag="32" IconVisible="False" HorizontalEdge="LeftEdge" VerticalEdge="TopEdge" LeftMargin="-120.0000" RightMargin="62.0000" BottomMargin="-55.0000" ctype="SpriteObjectData">
                <Size X="58.0000" Y="55.0000" />
                <AnchorPoint ScaleY="1.0000" />
                <Position X="-120.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="MarkedSubImage" Path="Resource/Item/Heart.png" Plist="Item.plist" />
                <BlendFunc Src="770" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="Sprite_HeartBrokenLeft" ActionTag="-1752033937" Tag="247" IconVisible="False" LeftMargin="-178.0000" RightMargin="146.0000" BottomMargin="-55.0000" ctype="SpriteObjectData">
                <Size X="32.0000" Y="55.0000" />
                <AnchorPoint ScaleY="1.0000" />
                <Position X="-178.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="MarkedSubImage" Path="Resource/Item/Heart_Broken_Left.png" Plist="Item.plist" />
                <BlendFunc Src="770" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="Sprite_HeartBrokenRight" ActionTag="235678988" Tag="602" IconVisible="False" LeftMargin="-157.0000" RightMargin="120.0000" BottomMargin="-55.0000" ctype="SpriteObjectData">
                <Size X="37.0000" Y="55.0000" />
                <AnchorPoint ScaleY="1.0000" />
                <Position X="-157.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="MarkedSubImage" Path="Resource/Item/Heart_Broken_Right.png" Plist="Item.plist" />
                <BlendFunc Src="770" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position Y="60.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition Y="0.0938" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="Node_CountDown" ActionTag="1286181810" Tag="490" IconVisible="True" LeftMargin="-220.0000" RightMargin="1180.0000" TopMargin="640.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="Node_GuideLineCountDown" ActionTag="845030047" Tag="83" IconVisible="True" HorizontalEdge="LeftEdge" TopMargin="-450.0000" BottomMargin="450.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="LoadingBar_Back" ActionTag="-1338486649" Tag="332" IconVisible="False" RightMargin="-220.0000" TopMargin="-16.0000" BottomMargin="-16.0000" ProgressInfo="100" ctype="LoadingBarObjectData">
                    <Size X="220.0000" Y="32.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="77" G="77" B="77" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="LoadingBar_CountDown" ActionTag="-2020144253" Tag="84" IconVisible="False" RightMargin="-220.0000" TopMargin="-15.0000" BottomMargin="-15.0000" ProgressInfo="100" ctype="LoadingBarObjectData">
                    <Size X="220.0000" Y="30.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Sprite_Item" ActionTag="1406621869" Tag="112" IconVisible="False" VerticalEdge="BothEdge" LeftMargin="5.0000" RightMargin="-57.0000" TopMargin="-26.0000" BottomMargin="-26.0000" ctype="SpriteObjectData">
                    <Size X="52.0000" Y="52.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="5.0000" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="MarkedSubImage" Path="Resource/Item/guideItem.png" Plist="Item.plist" />
                    <BlendFunc Src="770" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_CountDown" ActionTag="-132117225" Tag="85" IconVisible="False" VerticalEdge="BothEdge" LeftMargin="35.0000" RightMargin="-206.0000" TopMargin="-15.5000" BottomMargin="-15.5000" FontSize="22" LabelText="Guide Line: 10.0" VerticalAlignmentType="VT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="171.0000" Y="31.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="35.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="165" G="42" B="42" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position Y="450.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="230" G="230" B="250" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="Node_EnlargeCountDown" ActionTag="2099487235" Tag="113" IconVisible="True" HorizontalEdge="LeftEdge" TopMargin="-400.0000" BottomMargin="400.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="LoadingBar_Back" ActionTag="-2091753889" Tag="333" IconVisible="False" RightMargin="-220.0000" TopMargin="-16.0000" BottomMargin="-16.0000" ProgressInfo="100" ctype="LoadingBarObjectData">
                    <Size X="220.0000" Y="32.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="77" G="77" B="77" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="LoadingBar_CountDown" ActionTag="-792399373" Tag="114" IconVisible="False" RightMargin="-220.0000" TopMargin="-15.0000" BottomMargin="-15.0000" ProgressInfo="100" ctype="LoadingBarObjectData">
                    <Size X="220.0000" Y="30.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_CountDown" ActionTag="-1081316754" Tag="115" IconVisible="False" VerticalEdge="BothEdge" LeftMargin="35.0000" RightMargin="-172.0000" TopMargin="-15.5000" BottomMargin="-15.5000" FontSize="22" LabelText="Enlarge: 10.0" VerticalAlignmentType="VT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="137.0000" Y="31.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="35.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="165" G="42" B="42" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Sprite_Item" ActionTag="1172393417" Tag="186" IconVisible="False" LeftMargin="5.0000" RightMargin="-51.0000" TopMargin="-23.0000" BottomMargin="-23.0000" ctype="SpriteObjectData">
                    <Size X="51.0000" Y="52.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="5.0000" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="MarkedSubImage" Path="Resource/Item/enlargeItem.png" Plist="Item.plist" />
                    <BlendFunc Src="770" Dst="771" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position Y="400.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="230" G="230" B="250" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="Node_ShrinkCountDown" ActionTag="1163516227" Tag="116" IconVisible="True" HorizontalEdge="LeftEdge" TopMargin="-350.0000" BottomMargin="350.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="LoadingBar_Back" ActionTag="269713271" Tag="334" IconVisible="False" RightMargin="-220.0000" TopMargin="-16.0000" BottomMargin="-16.0000" ProgressInfo="100" ctype="LoadingBarObjectData">
                    <Size X="220.0000" Y="32.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="77" G="77" B="77" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="LoadingBar_CountDown" ActionTag="1510310398" Tag="117" IconVisible="False" RightMargin="-220.0000" TopMargin="-15.0000" BottomMargin="-15.0000" ProgressInfo="100" ctype="LoadingBarObjectData">
                    <Size X="220.0000" Y="30.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_CountDown" ActionTag="861580132" Tag="118" IconVisible="False" VerticalEdge="BothEdge" LeftMargin="35.0000" RightMargin="-162.0000" TopMargin="-15.5000" BottomMargin="-15.5000" FontSize="22" LabelText="Shrink: 10.0" VerticalAlignmentType="VT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="127.0000" Y="31.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="35.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="165" G="42" B="42" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Sprite_Item" ActionTag="-1944775913" Tag="254" IconVisible="False" LeftMargin="5.0000" RightMargin="-51.0000" TopMargin="-23.0000" BottomMargin="-23.0000" ctype="SpriteObjectData">
                    <Size X="51.0000" Y="51.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="5.0000" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="MarkedSubImage" Path="Resource/Item/shrinkItem.png" Plist="Item.plist" />
                    <BlendFunc Src="770" Dst="771" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position Y="350.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="230" G="230" B="250" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="Node_ShieldCountDown" ActionTag="-12386600" Tag="83" IconVisible="True" HorizontalEdge="LeftEdge" TopMargin="-300.0000" BottomMargin="300.0000" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="LoadingBar_Back" ActionTag="-229034317" Tag="335" IconVisible="False" RightMargin="-220.0000" TopMargin="-16.0000" BottomMargin="-16.0000" ProgressInfo="100" ctype="LoadingBarObjectData">
                    <Size X="220.0000" Y="32.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="77" G="77" B="77" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="LoadingBar_CountDown" ActionTag="196259629" Tag="84" IconVisible="False" RightMargin="-220.0000" TopMargin="-15.0000" BottomMargin="-15.0000" ProgressInfo="100" ctype="LoadingBarObjectData">
                    <Size X="220.0000" Y="30.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_CountDown" ActionTag="1334281053" Tag="85" IconVisible="False" VerticalEdge="BothEdge" LeftMargin="35.0000" RightMargin="-159.0000" TopMargin="-15.5000" BottomMargin="-15.5000" FontSize="22" LabelText="Shield: 10.0" VerticalAlignmentType="VT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="124.0000" Y="31.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="35.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
                    <OutlineColor A="255" R="165" G="42" B="42" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Sprite_Item" ActionTag="1922298045" Tag="255" IconVisible="False" LeftMargin="5.0000" RightMargin="-58.0000" TopMargin="-32.0000" BottomMargin="-32.0000" ctype="SpriteObjectData">
                    <Size X="53.0000" Y="64.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="5.0000" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="MarkedSubImage" Path="Resource/Item/shield.png" Plist="Item.plist" />
                    <BlendFunc Src="770" Dst="771" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position Y="300.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="230" G="230" B="250" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="-220.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="-0.2292" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>