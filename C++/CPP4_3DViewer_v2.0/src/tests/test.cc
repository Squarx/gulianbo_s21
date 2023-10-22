#include <gtest/gtest.h>

#include "../backend/file_reader/file_reader.h"
#include "../backend/normalization_parameters/norm_params.h"
namespace s21 {
std::shared_ptr<AbstractParcer> SolverStrategy::vertex_parcer_ = nullptr;
std::shared_ptr<AbstractParcer> SolverStrategy::facet_parcer_ = nullptr;

class TestS213DViewer : public ::testing::Test {
 public:
  s21::FileReader a;
  s21::FacetsParser fp;
  s21::VertexParser vp;
  s21::Figure figure;
  std::shared_ptr<AbstractParcer> strat{};
  s21::Vertex *v{};
  s21::Scene s;
  s21::NormParams np;

 protected:
  void SetUp() override { v = new Vertex(1, 2, 3); }
  void TearDown() override { delete v; }
};

TEST_F(TestS213DViewer, EmptyFile) {  // no exept
  a.SetFilePath("objects/nofile.obj");
  a.ReadScene();

  auto fig = a.GetScene().GetFigures();
  auto vert = fig[0].GetVertices();
  auto edg = fig[0].GetEdges();

  EXPECT_EQ(fig[0].GetVerticesDouble().size(), 0);
  EXPECT_EQ(fig[0].GetEdgesInt().size(), 0);
  EXPECT_EQ(vert.size(), 0);
  EXPECT_EQ(edg.size(), 0);
}

TEST_F(TestS213DViewer, SetPath) {  // incorrect file
  a.SetFilePath("objects/test234.obj");
  EXPECT_THROW(a.ReadScene(), std::runtime_error);
  a.SetFilePath("objects/test.obj");
  EXPECT_THROW(a.ReadScene(), std::runtime_error);
}

TEST_F(TestS213DViewer, SetPath2) {  // correct file
  a.SetFilePath("objects/cube.obj");
  auto scene = a.ReadScene();
  EXPECT_EQ(scene.GetFigures().size(), 1);
}

TEST_F(TestS213DViewer, IncorrectF1) {
  const std::string line = "f     ";
  EXPECT_THROW(fp.Parce(line, figure), std::runtime_error);
}

TEST_F(TestS213DViewer, IncorrectF2) {
  const std::string line = "f /// /// ///";
  EXPECT_THROW(fp.Parce(line, figure), std::runtime_error);
}

TEST_F(TestS213DViewer, IncorrectF3) {
  const std::string line = "f 1/2/3 /2/3 1/2/3";
  EXPECT_THROW(fp.Parce(line, figure), std::runtime_error);
}

TEST_F(TestS213DViewer, IncorrectF4) {
  const std::string line = "f 1/2/3";
  EXPECT_THROW(fp.Parce(line, figure), std::runtime_error);
}

TEST_F(TestS213DViewer, IncorrectV1) {
  const std::string line = "v 1 2     ";
  EXPECT_THROW(vp.Parce(line, figure), std::runtime_error);
}

TEST_F(TestS213DViewer, IncorrectV2) {
  const std::string line = "v 1 2 3 4";
  EXPECT_THROW(vp.Parce(line, figure), std::runtime_error);
}

TEST_F(TestS213DViewer, CorrectF2) {
  const std::string line = "f 1/2/3 4/5/6 7/8/9 10/11/12 13/14/15 16/17/18";
  strat = SolverStrategy::getInstance(line);
  strat->Parce(line, figure);
  EXPECT_EQ(figure.GetEdges().size(), 6);
}

TEST_F(TestS213DViewer, CorrectF) {
  const std::string line = "f 1/2/3 1/2/3 1/2/3 3/4/5 3/4/5 3/4/5";
  fp.Parce(line, figure);
  EXPECT_EQ(figure.GetEdges().size(), 6);
  EXPECT_EQ(figure.GetEdgesInt().size(), 12);
}

TEST_F(TestS213DViewer, CorrectV) {
  const std::string line = "v 1 2 3";
  strat = SolverStrategy::getInstance(line);
  strat->Parce(line, figure);
  EXPECT_EQ(figure.GetVertices().size(), 1);
}

TEST_F(TestS213DViewer, CorrectV2) {
  const std::string line = "v 1 2 3";
  vp.Parce(line, figure);
  EXPECT_EQ(figure.GetVertices().size(), 1);
}

TEST_F(TestS213DViewer, SolverIncorrStr) {
  const std::string line = "s 1 2 3";
  strat = SolverStrategy::getInstance(line);
  EXPECT_EQ(strat, nullptr);
}

TEST_F(TestS213DViewer, VertexTranslateScale) {
  v->TranslateX(1.2);
  v->TranslateY(1.2);
  v->TranslateZ(1.2);
  auto pos = v->GetPosition();
  EXPECT_EQ(pos.x, 2.2);
  EXPECT_EQ(pos.y, 3.2);
  EXPECT_EQ(pos.z, 4.2);
  v->Scale(3, 3, 3);
  pos = v->GetPosition();
  EXPECT_EQ(pos.x - 6.6 < 1e-7, 1);
  EXPECT_EQ(pos.y - 9.6 < 1e-7, 1);
  EXPECT_EQ(pos.z - 12.6 < 1e-7, 1);
}

TEST_F(TestS213DViewer, VertexRotateX) {
  v->RotateX(2);
  auto pos = v->GetPosition();
  EXPECT_EQ(pos.x, 1);
  EXPECT_EQ(pos.y - 1.89408316395 < 1e-7, 1);
  EXPECT_EQ(pos.z - 3.06797147441 < 1e-7, 1);
}

TEST_F(TestS213DViewer, VertexRotateY) {
  v->RotateY(2);
  auto pos = v->GetPosition();
  EXPECT_EQ(pos.x - 1.10408931708 < 1e-7, 1);
  EXPECT_EQ(pos.y, 2);
  EXPECT_EQ(pos.z - 2.96327298434 < 1e-7, 1);
}

TEST_F(TestS213DViewer, VertexRotateZ) {
  v->RotateZ(2);
  auto pos = v->GetPosition();
  EXPECT_EQ(pos.x - 0.92959183363 < 1e-7, 1);
  EXPECT_EQ(pos.y - 2.03368115071 < 1e-7, 1);
  EXPECT_EQ(pos.z, 3);
}

TEST_F(TestS213DViewer, VertexMove) {
  v->MoveX(5);
  v->MoveY(5);
  v->MoveZ(5);

  auto pos = v->GetPosition();
  EXPECT_EQ(pos.x, 6);
  EXPECT_EQ(pos.y, 7);
  EXPECT_EQ(pos.z, 8);
}

TEST_F(TestS213DViewer, FigureMoveVert) {
  figure.AddVertex(*v);
  figure.MoveVertexArray(2, 2, 2);

  auto vert = figure.GetVertices();
  auto pos = vert[0].GetPosition();
  EXPECT_EQ(vert.size(), 1);
  EXPECT_EQ(pos.x, 3);
  EXPECT_EQ(pos.y, 4);
  EXPECT_EQ(pos.z, 5);

  figure.MoveVertexArray(1, 1, 1);

  vert = figure.GetVertices();
  pos = vert[0].GetPosition();
  EXPECT_EQ(vert.size(), 1);
  EXPECT_EQ(pos.x, 2);
  EXPECT_EQ(pos.y, 3);
  EXPECT_EQ(pos.z, 4);
}

TEST_F(TestS213DViewer, FigureGets) {
  figure.AddVertex(*v);
  figure.AddVertex(*v);
  EXPECT_EQ(figure.GetVerticesDouble().size(), 6);
}

TEST_F(TestS213DViewer, FigureScaleVert) {
  figure.AddVertex(*v);
  figure.AddVertex(*v);
  figure.ScaleVertexArray(2, 2, 2);
  auto vert = figure.GetVertices();
  EXPECT_EQ(vert[0].GetPosition().x, 2);
  EXPECT_EQ(vert[0].GetPosition().y, 4);
  EXPECT_EQ(vert[0].GetPosition().z, 6);

  EXPECT_EQ(vert[1].GetPosition().x, 2);
  EXPECT_EQ(vert[1].GetPosition().y, 4);
  EXPECT_EQ(vert[1].GetPosition().z, 6);
}

TEST_F(TestS213DViewer, FigureVertexArrMove) {
  figure.AddVertex(*v);
  figure.AddVertex(*v);

  figure.MoveVertexArray(5, 5, 5);

  auto vert = figure.GetVertices();

  EXPECT_EQ(vert[0].GetPosition().x, 6);
  EXPECT_EQ(vert[0].GetPosition().y, 7);
  EXPECT_EQ(vert[0].GetPosition().z, 8);

  EXPECT_EQ(vert[1].GetPosition().x, 6);
  EXPECT_EQ(vert[1].GetPosition().y, 7);
  EXPECT_EQ(vert[1].GetPosition().z, 8);
}

TEST_F(TestS213DViewer, FigureNormVertexArrMove) {
  figure.AddVertex(*v);
  figure.AddVertex(*v);

  figure.NormMoveVertexArray(5, 5, 5);

  auto vert = figure.GetVertices();

  EXPECT_EQ(vert[0].GetPosition().x, 6);
  EXPECT_EQ(vert[0].GetPosition().y, 7);
  EXPECT_EQ(vert[0].GetPosition().z, 8);

  EXPECT_EQ(vert[1].GetPosition().x, 6);
  EXPECT_EQ(vert[1].GetPosition().y, 7);
  EXPECT_EQ(vert[1].GetPosition().z, 8);
}

TEST_F(TestS213DViewer, FigureRotateVertArr) {
  figure.AddVertex(*v);
  figure.AddVertex(*v);

  figure.RotateVertexArray(2, 2, 2);

  auto vert = figure.GetVertices();

  EXPECT_EQ(vert[0].GetPosition().x - 1.03968491177 < 1e-7, 1);
  EXPECT_EQ(vert[0].GetPosition().y - 1.93154428866 < 1e-7, 1);
  EXPECT_EQ(vert[0].GetPosition().z - 3.03120305236 < 1e-7, 1);

  EXPECT_EQ(vert[1].GetPosition().x - 1.03968491177 < 1e-7, 1);
  EXPECT_EQ(vert[1].GetPosition().y - 1.93154428866 < 1e-7, 1);
  EXPECT_EQ(vert[1].GetPosition().z - 3.03120305236 < 1e-7, 1);
}

TEST_F(TestS213DViewer, SceneScaleFigures) {
  figure.AddVertex(*v);
  figure.AddVertex(*v);
  figure.ScaleVertexArray(2, 2, 2);
  s.AddFigure(figure);
  s.ScaleFigures(2, 2, 2);

  auto v_f = s.GetFigures();
  auto vert = v_f[0].GetVertices();

  EXPECT_EQ(vert[0].GetPosition().x, 2);
  EXPECT_EQ(vert[0].GetPosition().y, 4);
  EXPECT_EQ(vert[0].GetPosition().z, 6);

  EXPECT_EQ(vert[1].GetPosition().x, 2);
  EXPECT_EQ(vert[1].GetPosition().y, 4);
  EXPECT_EQ(vert[1].GetPosition().z, 6);
}

TEST_F(TestS213DViewer, SceneScaleVertArr) {
  figure.AddVertex(*v);
  figure.AddVertex(*v);

  s.AddFigure(figure);
  s.NormScaleFigures(2);

  auto v_f = s.GetFigures();
  auto vert = v_f[0].GetVertices();

  EXPECT_EQ(vert[0].GetPosition().x, 2);
  EXPECT_EQ(vert[0].GetPosition().y, 4);
  EXPECT_EQ(vert[0].GetPosition().z, 6);

  EXPECT_EQ(vert[1].GetPosition().x, 2);
  EXPECT_EQ(vert[1].GetPosition().y, 4);
  EXPECT_EQ(vert[1].GetPosition().z, 6);
}

TEST_F(TestS213DViewer, SceneMoveFigure) {
  figure.AddVertex(*v);
  figure.AddVertex(*v);

  s.AddFigure(figure);

  s.MoveFigures(5, 5, 5);

  auto fig = s.GetFigures();

  for (const Figure &f : fig) {
    auto vert = f.GetVertices();

    EXPECT_EQ(vert[0].GetPosition().x, 6);
    EXPECT_EQ(vert[0].GetPosition().y, 7);
    EXPECT_EQ(vert[0].GetPosition().z, 8);

    EXPECT_EQ(vert[1].GetPosition().x, 6);
    EXPECT_EQ(vert[1].GetPosition().y, 7);
    EXPECT_EQ(vert[1].GetPosition().z, 8);
  }
}

TEST_F(TestS213DViewer, SceneNormMoveFigure) {
  figure.AddVertex(*v);
  figure.AddVertex(*v);

  s.AddFigure(figure);

  s.NormMoveFigures(5, 5, 5);

  auto fig = s.GetFigures();

  for (const Figure &f : fig) {
    auto vert = f.GetVertices();

    EXPECT_EQ(vert[0].GetPosition().x, 6);
    EXPECT_EQ(vert[0].GetPosition().y, 7);
    EXPECT_EQ(vert[0].GetPosition().z, 8);

    EXPECT_EQ(vert[1].GetPosition().x, 6);
    EXPECT_EQ(vert[1].GetPosition().y, 7);
    EXPECT_EQ(vert[1].GetPosition().z, 8);
  }
}

TEST_F(TestS213DViewer, SceneFigureRotate) {
  figure.AddVertex(*v);
  figure.AddVertex(*v);

  s.AddFigure(figure);

  s.RoatateFigures(2, 2, 2);

  auto fig = s.GetFigures();

  for (const Figure &f : fig) {
    auto vert = f.GetVertices();

    EXPECT_EQ(vert[0].GetPosition().x - 1.03968491177 < 1e-7, 1);
    EXPECT_EQ(vert[0].GetPosition().y - 1.93154428866 < 1e-7, 1);
    EXPECT_EQ(vert[0].GetPosition().z - 3.03120305236 < 1e-7, 1);

    EXPECT_EQ(vert[1].GetPosition().x - 1.03968491177 < 1e-7, 1);
    EXPECT_EQ(vert[1].GetPosition().y - 1.93154428866 < 1e-7, 1);
    EXPECT_EQ(vert[1].GetPosition().z - 3.03120305236 < 1e-7, 1);
  }
}

TEST_F(TestS213DViewer, NormParams) {
  np.ClearParams();

  figure.AddVertex(*v);
  v->Scale(2, 2, 2);
  figure.AddVertex(*v);
  v->Scale(3, 3, 3);
  figure.AddVertex(*v);

  np.CalculateParams(figure);

  EXPECT_EQ(np.x_min, 1);
  EXPECT_EQ(np.x_max, 6);
  EXPECT_EQ(np.x_mean, 3.5);

  EXPECT_EQ(np.y_min, 2);
  EXPECT_EQ(np.y_max, 12);
  EXPECT_EQ(np.y_mean, 7);

  EXPECT_EQ(np.z_min, 3);
  EXPECT_EQ(np.z_max, 18);
  EXPECT_EQ(np.z_mean, 10.5);

  EXPECT_EQ(np.max_distance, 15);
  EXPECT_EQ(np.scale_factor - 0.213333 < 1e-2, 1);

  np.ClearParams();
  EXPECT_EQ(np.x_max + np.x_min + np.y_max + np.y_min + np.z_max + np.z_min +
                np.scale_factor,
            0);

  np.UpdateFov(564.3);
  EXPECT_EQ(np.fov, 564.3);
}

TEST_F(TestS213DViewer, NormParams2) {
  np.ClearParams();
  auto v2 = *v;
  v2.Scale(2, 2, 2);

  figure.AddVertex(v2);
  figure.AddVertex(*v);
  v->Scale(2, 2, 2);
  v->Scale(3, 3, 3);
  figure.AddVertex(*v);

  np.CalculateParams(figure);

  EXPECT_EQ(np.x_min, 1);
  EXPECT_EQ(np.x_max, 6);
  EXPECT_EQ(np.x_mean, 3.5);

  EXPECT_EQ(np.y_min, 2);
  EXPECT_EQ(np.y_max, 12);
  EXPECT_EQ(np.y_mean, 7);

  EXPECT_EQ(np.z_min, 3);
  EXPECT_EQ(np.z_max, 18);
  EXPECT_EQ(np.z_mean, 10.5);

  EXPECT_EQ(np.max_distance, 15);
  EXPECT_EQ(np.scale_factor - 0.213333 < 1e-2, 1);

  np.ClearParams();
  EXPECT_EQ(np.x_max + np.x_min + np.y_max + np.y_min + np.z_max + np.z_min +
                np.scale_factor,
            0);

  np.UpdateFov(564.3);
  EXPECT_EQ(np.fov, 564.3);
}

}  // namespace s21

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}