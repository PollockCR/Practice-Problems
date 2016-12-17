using UnityEngine;
using System.Collections;

public class Fractal_materials : MonoBehaviour
{
    public Mesh[] meshes;
    //public Material material;
    public int maxDepth;
    private int depth;
    public float childScale;
    public float spawnProbability;
    public float maxRotationSpeed;
    private float rotationSpeed;
    public float maxTwist;
    private int mesh;

    public Material[] materials;

    private void InitializeMaterials(){
      /*
        materials = new Material[maxDepth + 1, 2];
        for(int i = 0; i <= maxDepth; i++){
            float t = i / (maxDepth - 1f);
            t *= t;
            materials[i, 0] = new Material(material);
            materials[i, 0].color =
              Color.Lerp(Color.white, Color.yellow, t);
            materials[i, 1] = new Material(material);
            materials[i, 1].color =
              Color.Lerp(Color.white, Color.cyan, t);
        }
        materials[maxDepth, 0].color = Color.green;
        materials[maxDepth, 1].color = Color.gray;
        */
    }

    private void Start()
    {

        rotationSpeed = Random.Range(-maxRotationSpeed, maxRotationSpeed);
        transform.Rotate(Random.Range(-maxTwist, maxTwist), 0f, 0f);
        if(materials == null){
            InitializeMaterials();
        }
        mesh = Random.Range(0, meshes.Length);
        gameObject.AddComponent<MeshFilter>().mesh = meshes[mesh];
        gameObject.AddComponent<MeshRenderer>().material = materials[mesh];
        if (depth < maxDepth)
        {
            StartCoroutine(CreateChildren());
        }
    }

    private void Update(){
        transform.Rotate(0f, rotationSpeed * Time.deltaTime, 0f);
    }

    private static Vector3[] childDirections = {
        Vector3.up,
        Vector3.right,
        Vector3.left,
        Vector3.forward,
        Vector3.back
    };

    private static Quaternion[] childOrientations = {
        Quaternion.identity,
        Quaternion.Euler(0f, 0f, -90f),
        Quaternion.Euler(0f, 0f, 90f),
        Quaternion.Euler(90f, 0f, 0f),
        Quaternion.Euler(-90f, 0f, 0f)

    };

    private IEnumerator CreateChildren(){
        for(int i = 0; i < childDirections.Length; i++){
            if(Random.value < spawnProbability){
                  yield return new WaitForSeconds(0.5f);
                    new GameObject("Fractal Child").AddComponent<Fractal_materials>().
                  Initialize(this, i);
              }
        }
    }

    private void Initialize(Fractal_materials parent, int childIndex)
    {
        meshes = parent.meshes;
        materials = parent.materials;
        maxDepth = parent.maxDepth;
        maxRotationSpeed = parent.maxRotationSpeed;
        maxTwist = parent.maxTwist;
        spawnProbability = parent.spawnProbability;
        depth = parent.depth + 1;
        childScale = parent.childScale;
        transform.parent = parent.transform;
        transform.localScale = Vector3.one * childScale;
        transform.localPosition = childDirections[childIndex] * (0.2f + 0.5f * childScale);
        transform.localRotation = childOrientations[childIndex];
    }
}
