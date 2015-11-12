<GameProjectFile>
  <PropertyGroup Type="Node" Name="PlayerNode" ID="0392ae04-9872-4fe7-9864-cdf4ca825b16" Version="2.3.2.3" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Node" Tag="126" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="Sprite_Player" ActionTag="-12689202" Tag="128" IconVisible="False" LeftMargin="-16.0000" RightMargin="-16.0000" TopMargin="-49.0000" ctype="SpriteObjectData">
            <Size X="32.0000" Y="49.0000" />
            <Children>
              <AbstractNodeData Name="Sprite_Shield" ActionTag="-1470063485" Tag="116" IconVisible="False" LeftMargin="33.0000" RightMargin="-54.0000" TopMargin="-8.0000" BottomMargin="-7.0000" FlipX="True" ctype="SpriteObjectData">
                <Size X="53.0000" Y="64.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="33.0000" Y="25.0000" />
                <Scale ScaleX="0.4000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="1.0313" Y="0.5102" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="Resource/shield.png" Plist="" />
                <BlendFunc Src="770" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Resource/Hero_right.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="LoadingBar_PlayerPower" ActionTag="-1277536332" Tag="129" RotationSkewX="-90.0000" RotationSkewY="-90.0042" IconVisible="False" LeftMargin="-125.0000" RightMargin="-75.0000" TopMargin="-57.0000" BottomMargin="43.0000" ProgressInfo="100" ctype="LoadingBarObjectData">
            <Size X="200.0000" Y="14.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="-25.0000" Y="50.0000" />
            <Scale ScaleX="0.3126" ScaleY="0.5360" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="Node_Heart" ActionTag="-1496806593" Tag="40" IconVisible="True" TopMargin="-80.0000" BottomMargin="80.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="Sprite_Heart" ActionTag="-605855242" Tag="38" IconVisible="False" LeftMargin="-58.0000" TopMargin="-27.5000" BottomMargin="-27.5000" ctype="SpriteObjectData">
                <Size X="58.0000" Y="55.0000" />
                <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                <Position />
                <Scale ScaleX="0.6000" ScaleY="0.6000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="Resource/Heart.png" Plist="" />
                <BlendFunc Src="770" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_HeartNumber" ActionTag="1249034655" Tag="39" IconVisible="False" RightMargin="-23.0000" TopMargin="-16.0000" BottomMargin="-16.0000" FontSize="26" LabelText="-1" HorizontalAlignmentType="HT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="23.0000" Y="32.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0542" Y="0.0359" />
                <FontResource Type="Normal" Path="Font/arial.ttf" Plist="" />
                <OutlineColor A="255" R="0" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position Y="80.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="Text_Good" ActionTag="968041203" Tag="86" IconVisible="False" LeftMargin="-64.5000" RightMargin="-64.5000" TopMargin="-183.5000" BottomMargin="116.5000" FontSize="32" LabelText="Good" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
            <Size X="84.0000" Y="46.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position Y="150.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.4823" Y="0.1484" />
            <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
            <OutlineColor A="255" R="30" G="144" B="255" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Text_Great" ActionTag="-369216070" Tag="87" IconVisible="False" LeftMargin="-43.0000" RightMargin="-43.0000" TopMargin="-223.0000" BottomMargin="177.0000" FontSize="32" LabelText="Great" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
            <Size X="86.0000" Y="46.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position Y="200.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.4823" Y="0.1484" />
            <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
            <OutlineColor A="255" R="128" G="0" B="128" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="Text_Perfect" ActionTag="-689463427" Tag="88" IconVisible="False" LeftMargin="-54.5000" RightMargin="-54.5000" TopMargin="-273.0000" BottomMargin="227.0000" FontSize="32" LabelText="Perfect" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
            <Size X="109.0000" Y="46.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position Y="250.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.4823" Y="0.1484" />
            <FontResource Type="Normal" Path="Font/msyh.ttc" Plist="" />
            <OutlineColor A="255" R="255" G="165" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>